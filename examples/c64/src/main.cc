#include "c64.hh"

#include "harpoon/log/console_log.hh"
#include "harpoon/exception/hardware_component_exception.hh"

#include <memory>
#include <condition_variable>
#include <mutex>
#include <csignal>

static std::condition_variable* signal_condition_variable{};
static std::mutex signal_mutex{};

static void signal_handler(int signal) {
	(void)signal;
	std::unique_lock<std::mutex> lk(signal_mutex);

	signal_condition_variable->notify_all();
}

int main() {

	auto console_log = harpoon::log::make_console_log();
	signal_condition_variable = new std::condition_variable;

	try {
		auto computer_system = std::make_shared<commodore::c64>(console_log);

		computer_system->create();

		computer_system->prepare();
		computer_system->boot();

		std::unique_lock<std::mutex> lk(signal_mutex);

		signal(SIGINT, signal_handler);

		signal_condition_variable->wait(lk);
		signal(SIGINT, SIG_IGN);

		computer_system->shutdown();
		computer_system->log_state();
		computer_system->cleanup();
	} catch (harpoon::exception::hardware_component_exception& error) {
		console_log->out(log_critical_c(error.get_component()) << error.what());
	} catch (std::exception& error) {
		console_log->out(log_critical << error.what());
	}

	delete signal_condition_variable;
}

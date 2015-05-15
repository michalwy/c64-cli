#include "harpoon/hardware_component.hh"
#include "harpoon/log/message.hh"

using namespace harpoon;

hardware_component::~hardware_component() {
	log(component_debug << "Destroying component.");
}

void hardware_component::add_component(const hardware_component_ptr& component) {
	_components.push_back(component);
	component->set_parent_component(shared_from_this());

	log(component_debug << "Adding component: " << component->get_name());
}


void hardware_component::replace_component(const hardware_component_ptr& old_component,
										   const hardware_component_ptr& new_component) {
	_components.remove(old_component);
	if (old_component) {
		old_component->set_parent_component(nullptr);
	}
	add_component(new_component);
}

const log::log_ptr& hardware_component::get_log() const {
	if (_log) {
		return _log;
	}

	if (_parent_component) {
		return _parent_component->get_log();
	}

	return _log;
}

void hardware_component::log(const std::ostream& stream) const {
	get_log()->out(stream);
}

void hardware_component::prepare() {
	for (auto& component : _components) {
		component->prepare();
	}
	boot();
}

void hardware_component::cleanup() {
	shutdown();
	for (auto& component : _components) {
		component->cleanup();
	}
	_components.clear();
}

void hardware_component::boot() {}

void hardware_component::shutdown() {}

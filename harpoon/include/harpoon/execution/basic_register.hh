#ifndef HARPOON_EXECUTION_BASIC_REGISTER_HH
#define HARPOON_EXECUTION_BASIC_REGISTER_HH

#include "harpoon/harpoon.hh"

#include <ostream>
#include <iomanip>

namespace harpoon {
namespace execution {

template<typename T>
class basic_register {
public:

	basic_register() {}
	basic_register(const basic_register&) = default;
	basic_register(const T& value) : _value(value) {}
	basic_register& operator=(const basic_register&) = default;
	basic_register& operator=(const T& value) {
		set_value(value);
		return *this;
	}

	const T& get_value() const {
		return _value;
	}

	void set_value(const T& value) {
		_value = value;
	}

private:

	T _value{};

};

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, const basic_register<T>& reg) {
	return stream 
		<< "[0x" 
		<< std::hex 
		<< std::setfill('0') 
		<< std::setw(sizeof(T) * 2) 
		<< reg.get_value() 
		<< "]";
}

template<>
inline std::ostream& operator<<(std::ostream& stream, const basic_register<std::uint8_t>& reg) {
	return stream
		<< "[0x"
		<< std::hex
		<< std::setfill('0')
		<< std::setw(2)
		<< static_cast<std::uint32_t>(reg.get_value())
		<< "]";
}

template<typename T>
using basic_register_ptr = std::shared_ptr<basic_register<T>>;

template<typename T>
using basic_register_weak_ptr = std::weak_ptr<basic_register<T>>;

template<typename T, typename... Args>
basic_register_ptr<T> make_basic_register(Args&&... args) {
	return std::make_shared<basic_register<T>>(std::forward<Args>(args)...);
}

}
}

#endif
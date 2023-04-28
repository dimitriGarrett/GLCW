#pragma once

#include "cti/cti/cti_type_info.h"

namespace GL
{
	template <cti::hash_t id, unsigned int v>
	struct BitfieldWrapper
	{
		constexpr static unsigned int value = v;
		
		template <unsigned int other>
		constexpr BitfieldWrapper<id, other | value> operator| (const BitfieldWrapper<id, other>& rhs) const
		{
			return BitfieldWrapper<id, value | rhs.value>{};
		}
	};

#define BITFIELD_WRAP(value) BitfieldWrapper<cti::type_info(__FILE__).hash(), static_cast<unsigned int>(value)>
}
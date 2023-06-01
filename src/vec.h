#pragma once

namespace math
{
	template <typename T>
	struct vec2
	{
		T x, y;

		const float& operator[] (int where) const
		{
			switch (where)
			{
			case 0: return x;
			case 1: return y;
			}
		}
	};

	template <typename T>
	struct vec3
	{
		T x, y, z;

		const float& operator[] (int where) const
		{
			switch (where)
			{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			}
		}
	};

	template <typename T>
	struct vec4
	{
		T x, y, z, w;

		const float& operator[] (int where) const
		{
			switch (where)
			{
			case 0: return x;
			case 1: return y;
			case 2: return z;
			case 3: return w;
			}
		}
	};

	struct matrix2
	{
		vec2<float> values[2];

		const vec2<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix3
	{
		vec3<float> values[3];

		const vec3<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix4
	{
		vec4<float> values[4];

		const vec4<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix2x3
	{
		vec3<float> values[2];

		const vec3<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix3x2
	{
		vec2<float> values[3];

		const vec2<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix2x4
	{
		vec4<float> values[2];

		const vec4<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix4x2
	{
		vec2<float> values[4];

		const vec2<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix4x3
	{
		vec3<float> values[4];

		const vec3<float>& operator[] (int where) const
		{
			return values[where];
		}
	};

	struct matrix3x4
	{
		vec4<float> values[3];

		const vec4<float>& operator[] (int where) const
		{
			return values[where];
		}
	};
}
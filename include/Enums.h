#pragma once

#include "Config.h"

#if _WIN32
	#undef NO_ERROR
	#undef WAIT_FAILED
#endif

namespace GL
{
	enum GL_ENUM : unsigned int
	{
		TEXTURE_MAX_ANISOTROPY = 0x84FE,

/* GPU STUFF */
		GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX = 0x9047,
		GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX = 0x9048,
		GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX = 0x9049,
		GPU_MEMORY_INFO_EVICTION_COUNT_NVX = 0x904A,
		GPU_MEMORY_INFO_EVICTED_MEMORY_NVX = 0x904B,
/* /GPU STUFF */

/* BufferObject.h */
		DOUBLE = 0x140A,
		UNSIGNED_BYTE = 0x1401,
		UNSIGNED_SHORT = 0x1403,
		UNSIGNED_INT = 0x1405,
		BYTE = 0x1400,
		SHORT = 0x1402,
		INT = 0x1404,
		FLOAT = 0x1406,
		HALF_FLOAT = 0x140B,
		FIXED = 0x140C,
		UNSIGNED_INT_2_10_10_10_10_REV = 0x8368,
		INT_2_10_10_10_10_REV = 0x8D9F,
		COPY_READ_BUFFER = 0x8F36,
		COPY_WRITE_BUFFER = 0x8F37,
		PIXEL_PACK_BUFFER = 0x88EB,
		PIXEL_UNPACK_BUFFER = 0x88EC,
		UNIFORM_BUFFER = 0x8A11,
		TRANSFORM_FEEDBACK_BUFFER = 0x8C8E,
		ATOMIC_COUNTER_BUFFER = 0x92C0,
		DISPATCH_INDIRECT_BUFFER = 0x90EE,
		SHADER_STORAGE_BUFFER = 0x90D2,
		QUERY_BUFFER = 0x9192,
		DRAW_INDIRECT_BUFFER = 0x8F3F,
		ARRAY_BUFFER = 0x8892,
		ELEMENT_ARRAY_BUFFER = 0x8893,
		STREAM_DRAW = 0x88E0,
		STREAM_READ = 0x88E1,
		STREAM_COPY = 0x88E2,
		STATIC_DRAW = 0x88E4,
		STATIC_READ = 0x88E5,
		STATIC_COPY = 0x88E6,
		DYNAMIC_DRAW = 0x88E8,
		DYNAMIC_READ = 0x88E9,
		DYNAMIC_COPY = 0x88EA,
		RGBA32F = 0x8814,
		RGBA16F = 0x881A,
		RGB32F = 0x8815,
		RGB32I = 0x8D83,
		RGB32UI = 0x8D71,
		RGBA32UI = 0x8D70,
		RGBA16UI = 0x8D76,
		RGBA8UI = 0x8D7C,
		RGBA32I = 0x8D82,
		RGBA16I = 0x8D88,
		RGBA8I = 0x8D8E,
		RGBA8 = 0x8058,
		RGBA16 = 0x805B,
		RG32UI = 0x823C,
		RG16UI = 0x823A,
		RG8UI = 0x8238,
		RG32I = 0x823B,
		RG16I = 0x8239,
		RG8I = 0x8237,
		RG32F = 0x8230,
		RG16F = 0x822F,
		RG16 = 0x822C,
		RG8 = 0x822B,
		R32UI = 0x8236,
		R16UI = 0x8234,
		R8UI = 0x8232,
		R32I = 0x8235,
		R16I = 0x8233,
		R8I = 0x8231,
		R32F = 0x822E,
		R16F = 0x822D,
		R16 = 0x822A,
		R8 = 0x8229,
		POINTS = 0x0000,
		LINE_STRIP = 0x0003,
		LINE_LOOP = 0x0002,
		LINES = 0x0001,
		TRIANGLES = 0x0004,
		TRIANGLE_STRIP = 0x0005,
		TRIANGLE_FAN = 0x0006,
		LINE_STRIP_ADJACENCY = 0x000B,
		LINES_ADJACENCY = 0x000A,
		TRIANGLE_STRIP_ADJACENCY = 0x000D,
		TRIANGLES_ADJACENCY = 0x000C,
		PATCHES = 0xE,
		BUFFER_ACCESS = 0x88BB,
		BUFFER_ACCESS_FLAGS = 0x911F,
		BUFFER_IMMUTABLE_STORAGE = 0x821F,
		BUFFER_MAPPED = 0x88BC,
		BUFFER_MAP_LENGTH = 0x9120,
		BUFFER_MAP_OFFSET = 0x9121,
		BUFFER_SIZE = 0x8764,
		BUFFER_STORAGE_FLAGS = 0x8220,
		BUFFER_USAGE = 0x8765,
		READ_ONLY = 0x88B8,
		WRITE_ONLY = 0x88B9,
		READ_WRITE = 0x88BA,
		PATCH_VERTICES = 0x8E72,
		PATCH_DEFAULT_OUTER_LEVEL = 0x8E74,
		PATCH_DEFAULT_INNER_LEVEL = 0x8E73,
		FIRST_VERTEX_CONVENTION = 0x8E4D,
		LAST_VERTEX_CONVENTION = 0x8E4E,
		INT_2_10_10_10_REV = 0x8D9F,
		UNSIGNED_INT_2_10_10_10_REV = 0x8368,
/* /BufferObject.h */

/* Debug.h */
		UNIFORM = 0x92E1,
		UNIFORM_BLOCK = 0x92E2,
		PROGRAM_INPUT = 0x92E3,
		PROGRAM_OUTPUT = 0x92E4,
		VERTEX_SUBROUTINE = 0x92E8,
		TESS_CONTROL_SUBROUTINE = 0x92E9,
		TESS_EVALUATION_SUBROUTINE = 0x92EA,
		GEOMETRY_SUBROUTINE = 0x92EB,
		FRAGMENT_SUBROUTINE = 0x92EC,
		COMPUTE_SUBROUTINE = 0x92ED,
		VERTEX_SUBROUTINE_UNIFORM = 0x92EE,
		TESS_CONTROL_SUBROUTINE_UNIFORM = 0x92EF,
		TESS_EVALUATION_SUBROUTINE_UNIFORM = 0x92F0,
		GEOMETRY_SUBROUTINE_UNIFORM = 0x92F1,
		FRAGMENT_SUBROUTINE_UNIFORM = 0x92F2,
		COMPUTE_SUBROUTINE_UNIFORM = 0x92F3,
		TRANSFORM_FEEDBACK_VARYING = 0x92F4,
		BUFFER_VARIABLE = 0x92E5,
		SHADER_STORAGE_BLOCK = 0x92E6,
		ACTIVE_RESOURCES = 0x92F5,
		MAX_NAME_LENGTH = 0x92F6,
		MAX_NUM_ACTIVE_VARIABLES = 0x92F7,
		MAX_NUM_COMPATIBLE_SUBROUTINES = 0x92F8,
		DEBUG_SOURCE_API = 0x8246,
		DEBUG_SOURCE_WINDOW_SYSTEM = 0x8247,
		DEBUG_SOURCE_SHADER_COMPILER = 0x8248,
		DEBUG_SOURCE_THIRD_PARTY = 0x8249,
		DEBUG_SOURCE_APPLICATION = 0x824A,
		DEBUG_SOURCE_OTHER = 0x824B,
		DONT_CARE = 0x1100,
		DEBUG_TYPE_ERROR = 0x824C,
		DEBUG_TYPE_DEPRECATED_BEHAVIOR = 0x824D,
		DEBUG_TYPE_UNDEFINED_BEHAVIOR = 0x824E,
		DEBUG_TYPE_PORTABILITY = 0x824F,
		DEBUG_TYPE_PERFORMANCE = 0x8250,
		DEBUG_TYPE_OTHER = 0x8251,
		DEBUG_TYPE_MARKER = 0x8268,
		DEBUG_TYPE_PUSH_GROUP = 0x8269,
		DEBUG_TYPE_POP_GROUP = 0x826A,
		DEBUG_SEVERITY_HIGH = 0x9146,
		DEBUG_SEVERITY_MEDIUM = 0x9147,
		DEBUG_SEVERITY_LOW = 0x9148,
		BUFFER = 0x82E0,
		SHADER = 0x82E1,
		PROGRAM = 0x82E2,
		QUERY = 0x82E3,
		PROGRAM_PIPELINE = 0x82E4,
		TRANSFORM_FEEDBACK = 0x8E22,
		SAMPLER = 0x82E6,
		TEXTURE = 0x1702,
		RENDERBUFFER = 0x8D41,
		FRAMEBUFFER = 0x8D40,
		DEBUG_CALLBACK_FUNCTION = 0x8244,
		DEBUG_CALLBACK_USER_PARAM = 0x8245,
/* /Debug.h */

/* FramebufferObject.h */
		ERROR_RETURNED = 0,
		FRAMEBUFFER_COMPLETE = 0x8CD5,
		FRAMEBUFFER_UNDEFINED = 0x8219,
		FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
		FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
		FRAMEBUFFER_UNSUPPORTED = 0x8CDD,
		FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56,
		FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER = 0x8CDB,
		FRAMEBUFFER_INCOMPLETE_READ_BUFFER = 0x8CDC,
		FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8,
		READ_FRAMEBUFFER = 0x8CA8,
		DRAW_FRAMEBUFFER = 0x8CA9,
		REPEAT = 0x2901,
		CLAMP = 0x2900,
		MIRRORED_REPEAT = 0x8370,
		CLAMP_TO_EDGE = 0x812F,
		CLAMP_TO_BORDER = 0x812D,
		NEAREST = 0x2600,
		LINEAR = 0x2601,
		NEAREST_MIPMAP_NEAREST = 0x2700,
		LINEAR_MIPMAP_NEAREST = 0x2701,
		NEAREST_MIPMAP_LINEAR = 0x2702,
		LINEAR_MIPMAP_LINEAR = 0x2703,
		DEPTH_ATTACHMENT = 0x8D00,
		STENCIL_ATTACHMENT = 0x8D20,
		DEPTH_STENCIL_ATTACHMENT = 0x821A,
		FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
		FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212,
		FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213,
		FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214,
		FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215,
		FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216,
		FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217,
		FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211,
		FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210,
		FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
		FRAMEBUFFER_ATTACHMENT_LAYERED = 0x8DA7,
		FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4,
		FRAMEBUFFER_DEFAULT_WIDTH = 0x9310,
		FRAMEBUFFER_DEFAULT_HEIGHT = 0x9311,
		FRAMEBUFFER_DEFAULT_LAYERS = 0x9312,
		FRAMEBUFFER_DEFAULT_SAMPLES = 0x9313,
		FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS = 0x9314,
		RENDERBUFFER_WIDTH = 0x8D42,
		RENDERBUFFER_HEIGHT = 0x8D43,
		RENDERBUFFER_INTERNAL_FORMAT = 0x8D44,
		RENDERBUFFER_SAMPLES = 0x8CAB,
		RENDERBUFFER_RED_SIZE = 0x8D50,
		RENDERBUFFER_GREEN_SIZE = 0x8D51,
		RENDERBUFFER_BLUE_SIZE = 0x8D52,
		RENDERBUFFER_ALPHA_SIZE = 0x8D53,
		RENDERBUFFER_DEPTH_SIZE = 0x8D54,
		RENDERBUFFER_STENCIL_SIZE = 0x8D55,

/* /FramebufferObject.h */

/* ProgramPipeline.h */
		ACTIVE_PROGRAM = 0x8259,
		VERTEX_SHADER = 0x8B31,
		FRAGMENT_SHADER = 0x8B30,
		INFO_LOG_LENGTH = 0x8B84,
		TESS_CONTROL_SHADER = 0x8E88,
		TESS_EVALUATION_SHADER = 0x8E87,
		GEOMETRY_SHADER = 0x8DD9,
		COMPUTE_SHADER = 0x91B9,
		VALIDATE_STATUS = 0x8B83,
/* /ProgramPipeline.h */

/* Queries.h  */
		QUERY_WAIT = 0x8E13,
		QUERY_NO_WAIT = 0x8E14,
		QUERY_BY_REGION_WAIT = 0x8E15,
		QUERY_BY_REGION_NO_WAIT = 0x8E16,
		ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
		SAMPLES_PASSED = 0x8914,
		PRIMITIVES_GENERATED = 0x8C87,
		ANY_SAMPLES_PASSED = 0x8C2F,
		CURRENT_QUERY = 0x8865,
		QUERY_COUNTER_BITS = 0x8864,
		TIME_ELAPSED = 0x88BF,
		TIMESTAMP = 0x8E28,
		QUERY_RESULT = 0x8866,
		QUERY_RESULT_NO_WAIT = 0x9194,
		QUERY_RESULT_AVAILABLE = 0x8867,
/* /Queries.h  */

/* Rendering.h */
		COLOR = 0x1800,
		DEPTH = 0x1801,
		STENCIL = 0x1802,
		BACK = 0x0405,
		NONE = 0,
		FRONT_LEFT = 0x0400,
		FRONT_RIGHT = 0x0401,
		BACK_LEFT = 0x0402,
		BACK_RIGHT = 0x0403,
		FRONT = 0x0404,
		LEFT = 0x0406,
		RIGHT = 0x0407,
		FRONT_AND_BACK = 0x0408,
		COLOR_ATTACHMENT0 = 0x8CE0,
		COLOR_ATTACHMENT1 = 0x8CE1,
		COLOR_ATTACHMENT2 = 0x8CE2,
		COLOR_ATTACHMENT3 = 0x8CE3,
		COLOR_ATTACHMENT4 = 0x8CE4,
		COLOR_ATTACHMENT5 = 0x8CE5,
		COLOR_ATTACHMENT6 = 0x8CE6,
		COLOR_ATTACHMENT7 = 0x8CE7,
		COLOR_ATTACHMENT8 = 0x8CE8,
		COLOR_ATTACHMENT9 = 0x8CE9,
		COLOR_ATTACHMENT10 = 0x8CEA,
		COLOR_ATTACHMENT11 = 0x8CEB,
		COLOR_ATTACHMENT12 = 0x8CEC,
		COLOR_ATTACHMENT13 = 0x8CED,
		COLOR_ATTACHMENT14 = 0x8CEE,
		COLOR_ATTACHMENT15 = 0x8CEF,
/* /Rendering.h */

/* Shaders.h */
		ATOMIC_COUNTER_BUFFER_BINDING = 0x92C1,
		ATOMIC_COUNTER_BUFFER_DATA_SIZE = 0x92C4,
		ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS = 0x92C5,
		ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES = 0x92C6,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER = 0x92C7,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER = 0x92C8,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x92C9,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER = 0x92CA,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER = 0x92CB,
		ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER = 0x90ED,
		FLOAT_VEC2 = 0x8B50,
		FLOAT_VEC3 = 0x8B51,
		FLOAT_VEC4 = 0x8B52,
		FLOAT_MAT2 = 0x8B5A,
		FLOAT_MAT3 = 0x8B5B,
		FLOAT_MAT4 = 0x8B5C,
		FLOAT_MAT2x3 = 0x8B65,
		FLOAT_MAT2x4 = 0x8B66,
		FLOAT_MAT3x2 = 0x8B67,
		FLOAT_MAT3x4 = 0x8B68,
		FLOAT_MAT4x2 = 0x8B69,
		FLOAT_MAT4x3 = 0x8B6A,
		INT_VEC2 = 0x8B53,
		INT_VEC3 = 0x8B54,
		INT_VEC4 = 0x8B55,
		UNSIGNED_INT_VEC2 = 0x8DC6,
		UNSIGNED_INT_VEC3 = 0x8DC7,
		UNSIGNED_INT_VEC4 = 0x8DC8,
		DOUBLE_VEC2 = 0x8FFC,
		DOUBLE_VEC3 = 0x8FFD,
		DOUBLE_VEC4 = 0x8FFE,
		DOUBLE_MAT2 = 0x8F46,
		DOUBLE_MAT3 = 0x8F47,
		DOUBLE_MAT4 = 0x8F48,
		DOUBLE_MAT2x3 = 0x8F49,
		DOUBLE_MAT2x4 = 0x8F4A,
		DOUBLE_MAT3x2 = 0x8F4B,
		DOUBLE_MAT3x4 = 0x8F4C,
		DOUBLE_MAT4x2 = 0x8F4D,
		DOUBLE_MAT4x3 = 0x8F4E,
		NUM_COMPATIBLE_SUBROUTINES = 0x8E4A,
		COMPATIBLE_SUBROUTINES = 0x8E4B,
		UNIFORM_SIZE = 0x8A38,
		UNIFORM_NAME_LENGTH = 0x8A39,
		IMAGE_1D = 0x904C,
		IMAGE_2D = 0x904D,
		IMAGE_3D = 0x904E,
		IMAGE_2D_RECT = 0x904F,
		IMAGE_CUBE = 0x9050,
		IMAGE_BUFFER = 0x9051,
		IMAGE_1D_ARRAY = 0x9052,
		IMAGE_2D_ARRAY = 0x9053,
		IMAGE_2D_MULTISAMPLE = 0x9055,
		IMAGE_2D_MULTISAMPLE_ARRAY = 0x9056,
		INT_IMAGE_1D = 0x9057,
		INT_IMAGE_2D = 0x9058,
		INT_IMAGE_3D = 0x9059,
		INT_IMAGE_2D_RECT = 0x905A,
		INT_IMAGE_CUBE = 0x905B,
		INT_IMAGE_BUFFER = 0x905C,
		INT_IMAGE_1D_ARRAY = 0x905D,
		INT_IMAGE_2D_ARRAY = 0x905E,
		INT_IMAGE_2D_MULTISAMPLE = 0x9060,
		INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x9061,
		UNSIGNED_INT_IMAGE_1D = 0x9062,
		UNSIGNED_INT_IMAGE_2D = 0x9063,
		UNSIGNED_INT_IMAGE_3D = 0x9064,
		UNSIGNED_INT_IMAGE_2D_RECT = 0x9065,
		UNSIGNED_INT_IMAGE_CUBE = 0x9066,
		UNSIGNED_INT_IMAGE_BUFFER = 0x9067,
		UNSIGNED_INT_IMAGE_1D_ARRAY = 0x9068,
		UNSIGNED_INT_IMAGE_2D_ARRAY = 0x9069,
		UNSIGNED_INT_IMAGE_2D_MULTISAMPLE = 0x906B,
		UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 0x906C,
		UNSIGNED_INT_ATOMIC_COUNTER = 0x92DB,
		INT_SAMPLER_1D = 0x8DC9,
		INT_SAMPLER_1D_ARRAY = 0x8DCE,
		INT_SAMPLER_2D_MULTISAMPLE = 0x9109,
		INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910C,
		INT_SAMPLER_BUFFER = 0x8DD0,
		INT_SAMPLER_2D_RECT = 0x8DCD,
		UNSIGNED_INT_SAMPLER_1D = 0x8DD1,
		UNSIGNED_INT_SAMPLER_1D_ARRAY = 0x8DD6,
		UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE = 0x910A,
		UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910D,
		UNSIGNED_INT_SAMPLER_BUFFER = 0x8DD8,
		UNSIGNED_INT_SAMPLER_2D_RECT = 0x8DD5,
		SAMPLER_1D = 0x8B5D,
		SAMPLER_1D_SHADOW = 0x8B61,
		SAMPLER_1D_ARRAY = 0x8DC0,
		SAMPLER_1D_ARRAY_SHADOW = 0x8DC3,
		SAMPLER_2D_MULTISAMPLE = 0x9108,
		SAMPLER_2D_MULTISAMPLE_ARRAY = 0x910B,
		SAMPLER_BUFFER = 0x8DC2,
		SAMPLER_2D_RECT = 0x8B63,
		SAMPLER_2D_RECT_SHADOW = 0x8B64,
		BOOL = 0x8B56,
		BOOL_VEC2 = 0x8B57,
		BOOL_VEC3 = 0x8B58,
		BOOL_VEC4 = 0x8B59,
		SAMPLER_2D = 0x8B5E,
		SAMPLER_3D = 0x8B5F,
		SAMPLER_CUBE = 0x8B60,
		SAMPLER_2D_SHADOW = 0x8B62,
		SAMPLER_2D_ARRAY = 0x8DC1,
		SAMPLER_2D_ARRAY_SHADOW = 0x8DC4,
		SAMPLER_CUBE_SHADOW = 0x8DC5,
		INT_SAMPLER_2D = 0x8DCA,
		INT_SAMPLER_3D = 0x8DCB,
		INT_SAMPLER_CUBE = 0x8DCC,
		INT_SAMPLER_2D_ARRAY = 0x8DCF,
		UNSIGNED_INT_SAMPLER_2D = 0x8DD2,
		UNSIGNED_INT_SAMPLER_3D = 0x8DD3,
		UNSIGNED_INT_SAMPLER_CUBE = 0x8DD4,
		UNSIGNED_INT_SAMPLER_2D_ARRAY = 0x8DD7,
		UNIFORM_BLOCK_BINDING = 0x8A3F,
		UNIFORM_BLOCK_DATA_SIZE = 0x8A40,
		UNIFORM_BLOCK_NAME_LENGTH = 0x8A41,
		UNIFORM_BLOCK_ACTIVE_UNIFORMS = 0x8A42,
		UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43,
		UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44,
		UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER = 0x8A45,
		UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46,
		UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER = 0x90EC,
		UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER = 0x84F0,
		UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER = 0x84F1,
		UNIFORM_TYPE = 0x8A37,
		UNIFORM_BLOCK_INDEX = 0x8A3A,
		UNIFORM_OFFSET = 0x8A3B,
		UNIFORM_ARRAY_STRIDE = 0x8A3C,
		UNIFORM_MATRIX_STRIDE = 0x8A3D,
		UNIFORM_IS_ROW_MAJOR = 0x8A3E,
		UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX = 0x92DA,
		COMPUTE_WORK_GROUP_SIZE = 0x8267,
		DELETE_STATUS = 0x8B80,
		LINK_STATUS = 0x8B82,
		ATTACHED_SHADERS = 0x8B85,
		ACTIVE_ATOMIC_COUNTER_BUFFERS = 0x92D9,
		ACTIVE_ATTRIBUTES = 0x8B89,
		ACTIVE_ATTRIBUTE_MAX_LENGTH = 0x8B8A,
		ACTIVE_UNIFORMS = 0x8B86,
		ACTIVE_UNIFORM_BLOCKS = 0x8A36,
		ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35,
		ACTIVE_UNIFORM_MAX_LENGTH = 0x8B87,
		TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F,
		TRANSFORM_FEEDBACK_VARYINGS = 0x8C83,
		TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76,
		PROGRAM_BINARY_LENGTH = 0x8741,
		GEOMETRY_VERTICES_OUT = 0x8916,
		GEOMETRY_INPUT_TYPE = 0x8917,
		GEOMETRY_OUTPUT_TYPE = 0x8918,
		PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257,
		PROGRAM_SEPARABLE = 0x8258,
		LOW_FLOAT = 0x8DF0,
		MEDIUM_FLOAT = 0x8DF1,
		HIGH_FLOAT = 0x8DF2,
		LOW_INT = 0x8DF3,
		MEDIUM_INT = 0x8DF4,
		HIGH_INT = 0x8DF5,
		SHADER_TYPE = 0x8B4F,
		COMPILE_STATUS = 0x8B81,
		SHADER_SOURCE_LENGTH = 0x8B88,
		ACTIVE_SUBROUTINE_UNIFORMS = 0x8DE6,
		ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS = 0x8E47,
		ACTIVE_SUBROUTINES = 0x8DE5,
		ACTIVE_SUBROUTINE_MAX_LENGTH = 0x8E48,
		ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH = 0x8E49,
		REFERENCED_BY_TESS_CONTROL_SHADER = 0x9307,
		REFERENCED_BY_TESS_EVALUATION_SHADER = 0x9308,
		REFERENCED_BY_GEOMETRY_SHADER = 0x9309,
		IS_PER_PATCH = 0x92E7,
		LOCATION_COMPONENT = 0x934A,
		TRANSFORM_FEEDBACK_BUFFER_INDEX = 0x934B,
		TRANSFORM_FEEDBACK_BUFFER_STRIDE = 0x934C,
		NAME_LENGTH = 0x92F9,
		TYPE = 0x92FA,
		ARRAY_SIZE = 0x92FB,
		OFFSET = 0x92FC,
		BLOCK_INDEX = 0x92FD,
		ARRAY_STRIDE = 0x92FE,
		MATRIX_STRIDE = 0x92FF,
		IS_ROW_MAJOR = 0x9300,
		ATOMIC_COUNTER_BUFFER_INDEX = 0x9301,
		BUFFER_BINDING = 0x9302,
		BUFFER_DATA_SIZE = 0x9303,
		NUM_ACTIVE_VARIABLES = 0x9304,
		ACTIVE_VARIABLES = 0x9305,
		REFERENCED_BY_VERTEX_SHADER = 0x9306,
		REFERENCED_BY_FRAGMENT_SHADER = 0x930A,
		REFERENCED_BY_COMPUTE_SHADER = 0x930B,
		TOP_LEVEL_ARRAY_SIZE = 0x930C,
		TOP_LEVEL_ARRAY_STRIDE = 0x930D,
		LOCATION = 0x930E,
		LOCATION_INDEX = 0x930F,
/* /Shaders.h */

/* State.h */
		FUNC_ADD = 0x8006,
		FUNC_SUBTRACT = 0x800A,
		FUNC_REVERSE_SUBTRACT = 0x800B,
		MIN = 0x8007,
		MAX = 0x8008,
		ZERO = 0,
		ONE = 1,
		SRC_COLOR = 0x0300,
		ONE_MINUS_SRC_COLOR = 0x0301,
		DST_COLOR = 0x0306,
		ONE_MINUS_DST_COLOR = 0x0307,
		SRC_ALPHA = 0x0302,
		ONE_MINUS_SRC_ALPHA = 0x0303,
		DST_ALPHA = 0x0304,
		ONE_MINUS_DST_ALPHA = 0x0305,
		CONSTANT_COLOR = 0x8001,
		ONE_MINUS_CONSTANT_COLOR = 0x8002,
		CONSTANT_ALPHA = 0x8003,
		ONE_MINUS_CONSTANT_ALPHA = 0x8004,
		LOWER_LEFT = 0x8CA1,
		UPPER_LEFT = 0x8CA2,
		NEGATIVE_ONE_TO_ONE = 0x935E,
		ZERO_TO_ONE = 0x935F,
		NEVER = 0x0200,
		LESS = 0x0201,
		EQUAL = 0x0202,
		LEQUAL = 0x0203,
		GREATER = 0x0204,
		NOTEQUAL = 0x0205,
		GEQUAL = 0x0206,
		ALWAYS = 0x0207,
		BLEND = 0x0BE2,
		CLIP_DISTANCE0 = 0x3000,
		CLIP_DISTANCE1 = 0x3001,
		CLIP_DISTANCE2 = 0x3002,
		CLIP_DISTANCE3 = 0x3003,
		CLIP_DISTANCE4 = 0x3004,
		CLIP_DISTANCE5 = 0x3005,
		COLOR_LOGIC_OP = 0x0BF2,
		DEPTH_CLAMP = 0x864F,
		FRAMEBUFFER_SRGB = 0x8DB9,
		LINE_SMOOTH = 0x0B20,
		MULTISAMPLE = 0x809D,
		POLYGON_SMOOTH = 0x0B41,
		POLYGON_OFFSET_LINE = 0x2A02,
		POLYGON_OFFSET_POINT = 0x2A01,
		PRIMITIVE_RESTART = 0x8F9D,
		SAMPLE_ALPHA_TO_ONE = 0x809F,
		SAMPLE_SHADING = 0x8C36,
		SAMPLE_MASK = 0x8E51,
		TEXTURE_CUBE_MAP_SEAMLESS = 0x884F,
		PROGRAM_POINT_SIZE = 0x8642,
		CULL_FACE = 0x0B44,
		DEPTH_TEST = 0x0B71,
		DITHER = 0x0BD0,
		POLYGON_OFFSET_FILL = 0x8037,
		RASTERIZER_DISCARD = 0x8C89,
		SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
		SAMPLE_COVERAGE = 0x80A0,
		SCISSOR_TEST = 0x0C11,
		STENCIL_TEST = 0x0B90,
		PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69,
		DEBUG_OUTPUT = 0x92E0,
		DEBUG_OUTPUT_SYNCHRONOUS = 0x8242,
		CW = 0x0900,
		CCW = 0x0901,
		MAX_DEBUG_MESSAGE_LENGTH = 0x9143,
		MAX_VIEWPORTS = 0x825B,
		VIEWPORT_SUBPIXEL_BITS = 0x825C,
		VIEWPORT_BOUNDS_RANGE = 0x825D,
		LAYER_PROVOKING_VERTEX = 0x825E,
		VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F,
		MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3,
		MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4,
		MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5,
		MIN_MAP_BUFFER_ALIGNMENT = 0x90BC,
		MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6,
		MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2,
		DISPATCH_INDIRECT_BUFFER_BINDING = 0x90EF,
		MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS = 0x8266,
		MAX_COMPUTE_ATOMIC_COUNTERS = 0x8265,
		MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS = 0x8264,
		MAX_COMPUTE_SHADER_STORAGE_BLOCKS = 0x90DB,
		MAX_COMPUTE_UNIFORM_BLOCKS = 0x91BB,
		MAX_COMPUTE_TEXTURE_IMAGE_UNITS = 0x91BC,
		MAX_COMPUTE_UNIFORM_COMPONENTS = 0x8263,
		MAX_COMPUTE_WORK_GROUP_INVOCATIONS = 0x90EB,
		MAX_COMPUTE_WORK_GROUP_COUNT = 0x91BE,
		MAX_COMPUTE_WORK_GROUP_SIZE = 0x91BF,
		MAX_FRAGMENT_SHADER_STORAGE_BLOCKS = 0x90DA,
		MAX_FRAMEBUFFER_WIDTH = 0x9315,
		MAX_FRAMEBUFFER_HEIGHT = 0x9316,
		MAX_FRAMEBUFFER_SAMPLES = 0x9318,
		MAX_UNIFORM_LOCATIONS = 0x826E,
		MAX_VERTEX_SHADER_STORAGE_BLOCKS = 0x90D6,
		VERTEX_BINDING_DIVISOR = 0x82D6,
		VERTEX_BINDING_OFFSET = 0x82D7,
		VERTEX_BINDING_STRIDE = 0x82D8,
		MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9,
		MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA,
		MAX_ELEMENT_INDEX = 0x8D6B,
		MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C,
		DEBUG_GROUP_STACK_DEPTH = 0x826D,
		MAX_LABEL_LENGTH = 0x82E8,
		MAX_FRAMEBUFFER_LAYERS = 0x9317,
		MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8,
		MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9,
		MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7,
		TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F,
		MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7,
		MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC,
		ARRAY_BUFFER_BINDING = 0x889D,
		CONTEXT_FLAGS = 0x821E,
		DOUBLEBUFFER = 0x0C32,
		LINE_SMOOTH_HINT = 0x0C52,
		LOGIC_OP_MODE = 0x0BF0,
		MAX_CLIP_DISTANCES = 0x0D32,
		MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS = 0x8A32,
		MAX_DEPTH_TEXTURE_SAMPLES = 0x910F,
		MAX_DUAL_SOURCE_DRAW_BUFFERS = 0x88FC,
		MAX_FRAGMENT_UNIFORM_BLOCKS = 0x8A2D,
		MAX_GEOMETRY_INPUT_COMPONENTS = 0x9123,
		MAX_GEOMETRY_OUTPUT_COMPONENTS = 0x9124,
		MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29,
		MAX_GEOMETRY_UNIFORM_BLOCKS = 0x8A2C,
		MAX_GEOMETRY_UNIFORM_COMPONENTS = 0x8DDF,
		MAX_RECTANGLE_TEXTURE_SIZE = 0x84F8,
		MAX_TEXTURE_BUFFER_SIZE = 0x8C2B,
		MAX_VARYING_FLOATS = 0x8B4B,
		MAX_VERTEX_ATTRIBS = 0x8869,
		PACK_IMAGE_HEIGHT = 0x806C,
		PACK_LSB_FIRST = 0x0D01,
		PACK_SKIP_IMAGES = 0x806B,
		PACK_SWAP_BYTES = 0x0D00,
		POINT_FADE_THRESHOLD_SIZE = 0x8128,
		PRIMITIVE_RESTART_INDEX = 0x8F9E,
		PROVOKING_VERTEX = 0x8E4F,
		POINT_SIZE = 0x0B11,
		POINT_SIZE_GRANULARITY = 0x0B13,
		POINT_SIZE_RANGE = 0x0B12,
		POLYGON_SMOOTH_HINT = 0x0C53,
		READ_BUFFER = 0x0C02,
		SAMPLE_MASK_VALUE = 0x8E52,
		SMOOTH_LINE_WIDTH_RANGE = 0x0B22,
		SMOOTH_LINE_WIDTH_GRANULARITY = 0x0B23,
		STEREO = 0x0C33,
		TEXTURE_BINDING_1D = 0x8068,
		TEXTURE_BINDING_1D_ARRAY = 0x8C1C,
		TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY = 0x9105,
		TEXTURE_BINDING_BUFFER = 0x8C2C,
		TEXTURE_BINDING_CUBE_MAP = 0x8514,
		TEXTURE_BINDING_RECTANGLE = 0x84F6,
		TEXTURE_COMPRESSION_HINT = 0x84EF,
		UNPACK_LSB_FIRST = 0x0CF1,
		UNPACK_SWAP_BYTES = 0x0CF0,
		ALIASED_POINT_SIZE_RANGE = 0x846D,
		RED_BITS = 0x0D52,
		GREEN_BITS = 0x0D53,
		BLUE_BITS = 0x0D54,
		ALPHA_BITS = 0x0D55,
		DEPTH_BITS = 0x0D56,
		STENCIL_BITS = 0x0D57,
		COPY_READ_BUFFER_BINDING = 0x8F36,
		COPY_WRITE_BUFFER_BINDING = 0x8F37,
		CULL_FACE_MODE = 0x0B45,
		FRONT_FACE = 0x0B46,
		GENERATE_MIPMAP_HINT = 0x8192,
		IMAGE_BINDING_LAYERED = 0x8F3C,
		MAX_ATOMIC_COUNTER_BUFFER_BINDINGS = 0x92DC,
		MAX_COLOR_ATTACHMENTS = 0x8CDF,
		MAX_SAMPLES = 0x8D57,
		MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE,
		MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
		ACTIVE_TEXTURE = 0x84E0,
		ALIASED_LINE_WIDTH_RANGE = 0x846E,
		BLEND_COLOR = 0x8005,
		BLEND_DST_ALPHA = 0x80CA,
		BLEND_DST_RGB = 0x80C8,
		BLEND_EQUATION_ALPHA = 0x883D,
		BLEND_EQUATION_RGB = 0x8009,
		BLEND_SRC_ALPHA = 0x80CB,
		BLEND_SRC_RGB = 0x80C9,
		COLOR_CLEAR_VALUE = 0x0C22,
		COLOR_WRITEMASK = 0x0C23,
		COMPRESSED_TEXTURE_FORMATS = 0x86A3,
		CURRENT_PROGRAM = 0x8B8D,
		DEPTH_CLEAR_VALUE = 0x0B73,
		DEPTH_FUNC = 0x0B74,
		DEPTH_RANGE = 0x0B70,
		DEPTH_WRITEMASK = 0x0B72,
		DRAW_BUFFER0 = 0x8825,
		DRAW_BUFFER1 = 0x8826,
		DRAW_BUFFER2 = 0x8827,
		DRAW_BUFFER3 = 0x8828,
		DRAW_BUFFER4 = 0x8829,
		DRAW_BUFFER5 = 0x882A,
		DRAW_BUFFER6 = 0x882B,
		DRAW_BUFFER7 = 0x882C,
		DRAW_BUFFER8 = 0x882D,
		DRAW_BUFFER9 = 0x882E,
		DRAW_BUFFER10 = 0x882F,
		DRAW_BUFFER11 = 0x8830,
		DRAW_BUFFER12 = 0x8831,
		DRAW_BUFFER13 = 0x8832,
		DRAW_BUFFER14 = 0x8833,
		DRAW_BUFFER15 = 0x8834,
		DRAW_FRAMEBUFFER_BINDING = 0x8CA6,
		ELEMENT_ARRAY_BUFFER_BINDING = 0x8895,
		FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
		IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
		IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
		LINE_WIDTH = 0x0B21,
		MAJOR_VERSION = 0x821B,
		MAX_3D_TEXTURE_SIZE = 0x8073,
		MAX_ARRAY_TEXTURE_LAYERS = 0x88FF,
		MAX_COLOR_TEXTURE_SAMPLES = 0x910E,
		MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33,
		MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
		MAX_COMBINED_UNIFORM_BLOCKS = 0x8A2E,
		MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31,
		MAX_CUBE_MAP_TEXTURE_SIZE = 0x851C,
		MAX_DRAW_BUFFERS = 0x8824,
		MAX_ELEMENTS_INDICES = 0x80E9,
		MAX_ELEMENTS_VERTICES = 0x80E8,
		MAX_FRAGMENT_INPUT_COMPONENTS = 0x9125,
		MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49,
		MAX_FRAGMENT_UNIFORM_VECTORS = 0x8DFD,
		MAX_INTEGER_SAMPLES = 0x9110,
		MAX_PROGRAM_TEXEL_OFFSET = 0x8905,
		MAX_RENDERBUFFER_SIZE = 0x84E8,
		MAX_SAMPLE_MASK_WORDS = 0x8E59,
		MAX_SERVER_WAIT_TIMEOUT = 0x9111,
		MAX_SHADER_STORAGE_BUFFER_BINDINGS = 0x90DD,
		MAX_TEXTURE_IMAGE_UNITS = 0x8872,
		MAX_TEXTURE_LOD_BIAS = 0x84FD,
		MAX_TEXTURE_SIZE = 0x0D33,
		MAX_UNIFORM_BUFFER_BINDINGS = 0x8A2F,
		MAX_UNIFORM_BLOCK_SIZE = 0x8A30,
		MAX_VARYING_COMPONENTS = 0x8B4B,
		MAX_VARYING_VECTORS = 0x8DFC,
		MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
		MAX_VERTEX_OUTPUT_COMPONENTS = 0x9122,
		MAX_VERTEX_UNIFORM_BLOCKS = 0x8A2B,
		MAX_VERTEX_UNIFORM_COMPONENTS = 0x8B4A,
		MAX_VERTEX_UNIFORM_VECTORS = 0x8DFB,
		MAX_VIEWPORT_DIMS = 0x0D3A,
		MIN_PROGRAM_TEXEL_OFFSET = 0x8904,
		MINOR_VERSION = 0x821C,
		NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
		NUM_EXTENSIONS = 0x821D,
		NUM_PROGRAM_BINARY_FORMATS = 0x87FE,
		NUM_SHADER_BINARY_FORMATS = 0x8DF9,
		PACK_ALIGNMENT = 0x0D05,
		PACK_ROW_LENGTH = 0x0D02,
		PACK_SKIP_PIXELS = 0x0D04,
		PACK_SKIP_ROWS = 0x0D03,
		PIXEL_PACK_BUFFER_BINDING = 0x88ED,
		PIXEL_UNPACK_BUFFER_BINDING = 0x88EF,
		POLYGON_OFFSET_FACTOR = 0x8038,
		POLYGON_OFFSET_UNITS = 0x2A00,
		PROGRAM_BINARY_FORMATS = 0x87FF,
		PROGRAM_PIPELINE_BINDING = 0x825A,
		READ_FRAMEBUFFER_BINDING = 0x8CAA,
		RENDERBUFFER_BINDING = 0x8CA7,
		SAMPLE_BUFFERS = 0x80A8,
		SAMPLE_COVERAGE_VALUE = 0x80AA,
		SAMPLE_COVERAGE_INVERT = 0x80AB,
		SAMPLER_BINDING = 0x8919,
		SCISSOR_BOX = 0x0C10,
		SHADER_COMPILER = 0x8DFA,
		SHADER_STORAGE_BUFFER_BINDING = 0x90D3,
		SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT = 0x90DF,
		SHADER_STORAGE_BUFFER_START = 0x90D4,
		SHADER_STORAGE_BUFFER_SIZE = 0x90D5,
		STENCIL_BACK_FAIL = 0x8801,
		STENCIL_BACK_FUNC = 0x8800,
		STENCIL_BACK_PASS_DEPTH_FAIL = 0x8802,
		STENCIL_BACK_PASS_DEPTH_PASS = 0x8803,
		STENCIL_BACK_REF = 0x8CA3,
		STENCIL_BACK_VALUE_MASK = 0x8CA4,
		STENCIL_BACK_WRITEMASK = 0x8CA5,
		STENCIL_CLEAR_VALUE = 0x0B91,
		STENCIL_FAIL = 0x0B94,
		STENCIL_FUNC = 0x0B92,
		STENCIL_PASS_DEPTH_FAIL = 0x0B95,
		STENCIL_PASS_DEPTH_PASS = 0x0B96,
		STENCIL_REF = 0x0B97,
		STENCIL_VALUE_MASK = 0x0B93,
		STENCIL_WRITEMASK = 0x0B98,
		SUBPIXEL_BITS = 0x0D50,
		TEXTURE_BINDING_2D = 0x8069,
		TEXTURE_BINDING_2D_ARRAY = 0x8C1D,
		TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104,
		TEXTURE_BINDING_3D = 0x806A,
		UNIFORM_BUFFER_BINDING = 0x8A28,
		UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34,
		UNIFORM_BUFFER_SIZE = 0x8A2A,
		UNIFORM_BUFFER_START = 0x8A29,
		UNPACK_ALIGNMENT = 0x0CF5,
		UNPACK_IMAGE_HEIGHT = 0x806E,
		UNPACK_ROW_LENGTH = 0x0CF2,
		UNPACK_SKIP_IMAGES = 0x806D,
		UNPACK_SKIP_PIXELS = 0x0CF4,
		UNPACK_SKIP_ROWS = 0x0CF3,
		VERTEX_ARRAY_BINDING = 0x85B5,
		VIEWPORT = 0x0BA2,
		INVALID_ENUM = 0x0500,
		INVALID_VALUE = 0x0501,
		INVALID_OPERATION = 0x0502,
		INVALID_FRAMEBUFFER_OPERATION = 0x0506,
		OUT_OF_MEMORY = 0x0505,
		STACK_UNDERFLOW = 0x0504,
		STACK_OVERFLOW = 0x0503,
		FASTEST = 0x1101,
		NICEST = 0x1102,
		CLEAR = 0x1500,
		SET = 0x150F,
		COPY = 0x1503,
		COPY_INVERTED = 0x150C,
		NOOP = 0x1505,
		INVERT = 0x150A,
		AND = 0x1501,
		NAND = 0x150E,
		OR = 0x1507,
		NOR = 0x1508,
		XOR = 0x1506,
		EQUIV = 0x1509,
		AND_REVERSE = 0x1502,
		AND_INVERTED = 0x1504,
		OR_REVERSE = 0x150B,
		OR_INVERTED = 0x150D,
		POINT_SPRITE_COORD_ORIGIN = 0x8CA0,
		POINT = 0x1B00,
		LINE = 0x1B01,
		FILL = 0x1B02,
		KEEP = 0x1E00,
		REPLACE = 0x1E01,
		INCR = 0x1E02,
		DECR = 0x1E03,
		INCR_WRAP = 0x8507,
		DECR_WRAP = 0x8508,
/* /State.h */

/* Syncing.h */
		ALREADY_SIGNALED = 0x911A,
		TIMEOUT_EXPIRED = 0x911B,
		CONDITION_SATISFIED = 0x911C,
		WAIT_FAILED = 0x911D,
		OBJECT_TYPE = 0x9112,
		SYNC_STATUS = 0x9114,
		SYNC_CONDITION = 0x9113,
		SYNC_FLAGS = 0x9115,
/* /Syncing.h */

/* Textures.h */
		TEXTURE_1D = 0x0DE0,
		TEXTURE_2D = 0x0DE1,
		TEXTURE_3D = 0x806F,
		TEXTURE_1D_ARRAY = 0x8C18,
		TEXTURE_2D_ARRAY = 0x8C1A,
		TEXTURE_RECTANGLE = 0x84F5,
		TEXTURE_CUBE_MAP = 0x8513,
		TEXTURE_CUBE_MAP_ARRAY = 0x9009,
		TEXTURE_BUFFER = 0x8C2A,
		TEXTURE_2D_MULTISAMPLE = 0x9100,
		TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9102,
		RGBA8_SNORM = 0x8F97,
		R11F_G11F_B10F = 0x8C3A,
		RGB10_A2UI = 0x906F,
		RGB10_A2 = 0x8059,
		RGBA16_SNORM = 0x8F9B,
		RG16_SNORM = 0x8F99,
		RG8_SNORM = 0x8F95,
		R16_SNORM = 0x8F98,
		R8_SNORM = 0x8F94,
		DEPTH_COMPONENT = 0x1902,
		DEPTH_STENCIL = 0x84F9,
		STENCIL_INDEX = 0x1901,
		STENCIL_INDEX8 = 0x8D48,
		DEPTH_COMPONENT16 = 0x81A5,
		DEPTH_COMPONENT24 = 0x81A6,
		DEPTH_COMPONENT32 = 0x81A7,
		RED = 0x1903,
		RG = 0x8227,
		RGB = 0x1907,
		RGBA = 0x1908,
		BGR = 0x80E0,
		BGRA = 0x80E1,
		COMPRESSED_RED = 0x8225,
		COMPRESSED_RG = 0x8226,
		COMPRESSED_RGB = 0x84ED,
		COMPRESSED_RGBA = 0x84EE,
		COMPRESSED_SRGB = 0x8C48,
		COMPRESSED_SRGB_ALPHA = 0x8C49,
		COMPRESSED_RED_RGTC1 = 0x8DBB,
		COMPRESSED_SIGNED_RED_RGTC1 = 0x8DBC,
		COMPRESSED_RG_RGTC2 = 0x8DBD,
		COMPRESSED_SIGNED_RG_RGTC2 = 0x8DBE,
		COMPRESSED_RGBA_BPTC_UNORM = 0x8E8C,
		COMPRESSED_SRGB_ALPHA_BPTC_UNORM = 0x8E8D,
		COMPRESSED_RGB_BPTC_SIGNED_FLOAT = 0x8E8E,
		COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = 0x8E8F,
		R3_G3_B2 = 0x2A10,
		RGB4 = 0x804F,
		RGB5 = 0x8050,
		RGB8 = 0x8051,
		RGB8_SNORM = 0x8F96,
		RGB10 = 0x8052,
		RGB12 = 0x8053,
		RGB16 = 0x8054,
		RGB16_SNORM = 0x8F9A,
		RGBA2 = 0x8055,
		RGBA4 = 0x8056,
		RGB5_A1 = 0x8057,
		RGBA12 = 0x805A,
		SRGB8 = 0x8C41,
		SRGB8_ALPHA8 = 0x8C43,
		RGB16F = 0x881B,
		RGB9_E5 = 0x8C3D,
		COMPRESSED_RGB8_ETC2 = 0x9274,
		COMPRESSED_SRGB8_ETC2 = 0x9275,
		COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276,
		COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277,
		COMPRESSED_RGBA8_ETC2_EAC = 0x9278,
		COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279,
		COMPRESSED_R11_EAC = 0x9270,
		COMPRESSED_SIGNED_R11_EAC = 0x9271,
		COMPRESSED_RG11_EAC = 0x9272,
		COMPRESSED_SIGNED_RG11_EAC = 0x9273,
		UNSIGNED_SHORT_5_6_5 = 0x8363,
		UNSIGNED_SHORT_4_4_4_4 = 0x8033,
		UNSIGNED_SHORT_5_5_5_1 = 0x8034,
		UNSIGNED_BYTE_3_3_2 = 0x8032,
		UNSIGNED_BYTE_2_3_3_REV = 0x8362,
		UNSIGNED_SHORT_5_6_5_REV = 0x8364,
		UNSIGNED_SHORT_4_4_4_4_REV = 0x8365,
		UNSIGNED_SHORT_1_5_5_5_REV = 0x8366,
		UNSIGNED_INT_8_8_8_8 = 0x8035,
		UNSIGNED_INT_8_8_8_8_REV = 0x8367,
		UNSIGNED_INT_10_10_10_2 = 0x8036,
		UNSIGNED_INT_10F_11F_11F_REV = 0x8C3B,
		UNSIGNED_INT_5_9_9_9_REV = 0x8C3E,
		UNSIGNED_INT_24_8 = 0x84FA,
		FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD,
		PROXY_TEXTURE_1D = 0x8063,
		PROXY_TEXTURE_2D = 0x8064,
		PROXY_TEXTURE_1D_ARRAY = 0x8C19,
		TEXTURE_CUBE_MAP_POSITIVE_X = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x851A,
		PROXY_TEXTURE_CUBE_MAP = 0x851B,
		PROXY_TEXTURE_CUBE_MAP_ARRAY = 0x900B,
		PROXY_TEXTURE_3D = 0x8070,
		PROXY_TEXTURE_2D_ARRAY = 0x8C1B,
		ALPHA = 0x1906,
		LUMINANCE = 0x1909,
		LUMINANCE_ALPHA = 0x190A,
		RGB565 = 0x8D62,
		GREEN = 0x1904,
		BLUE = 0x1905,
		RED_INTEGER = 0x8D94,
		GREEN_INTEGER = 0x8D95,
		BLUE_INTEGER = 0x8D96,
		RG_INTEGER = 0x8228,
		RGB_INTEGER = 0x8D98,
		RGBA_INTEGER = 0x8D99,
		BGR_INTEGER = 0x8D9A,
		BGRA_INTEGER = 0x8D9B,
		PROXY_TEXTURE_RECTANGLE = 0x84F7,
		PROXY_TEXTURE_2D_MULTISAMPLE = 0x9101,
		PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY = 0x9103,
		TEXTURE_WIDTH = 0x1000,
		TEXTURE_HEIGHT = 0x1001,
		TEXTURE_DEPTH = 0x8071,
		TEXTURE_INTERNAL_FORMAT = 0x1003,
		TEXTURE_SAMPLES = 0x9106,
		TEXTURE_FIXED_SAMPLE_LOCATIONS = 0x9107,
		TEXTURE_STENCIL_SIZE = 0x88F1,
		TEXTURE_SHARED_SIZE = 0x8C3F,
		TEXTURE_RED_TYPE = 0x8C10,
		TEXTURE_GREEN_TYPE = 0x8C11,
		TEXTURE_BLUE_TYPE = 0x8C12,
		TEXTURE_ALPHA_TYPE = 0x8C13,
		TEXTURE_DEPTH_TYPE = 0x8C16,
		TEXTURE_COMPRESSED = 0x86A1,
		TEXTURE_RED_SIZE = 0x805C,
		TEXTURE_GREEN_SIZE = 0x805D,
		TEXTURE_BLUE_SIZE = 0x805E,
		TEXTURE_ALPHA_SIZE = 0x805F,
		TEXTURE_DEPTH_SIZE = 0x884A,
		TEXTURE_COMPRESSED_IMAGE_SIZE = 0x86A0,
		TEXTURE_BUFFER_OFFSET = 0x919D,
		TEXTURE_BUFFER_SIZE = 0x919E,
		TEXTURE_BORDER_COLOR = 0x1004,
		TEXTURE_LOD_BIAS = 0x8501,
		TEXTURE_SWIZZLE_RGBA = 0x8E46,
		DEPTH_STENCIL_TEXTURE_MODE = 0x90EA,
		TEXTURE_BASE_LEVEL = 0x813C,
		TEXTURE_COMPARE_MODE = 0x884C,
		TEXTURE_COMPARE_FUNC = 0x884D,
		TEXTURE_MAG_FILTER = 0x2800,
		TEXTURE_MAX_LEVEL = 0x813D,
		TEXTURE_MAX_LOD = 0x813B,
		TEXTURE_MIN_FILTER = 0x2801,
		TEXTURE_MIN_LOD = 0x813A,
		TEXTURE_SWIZZLE_R = 0x8E42,
		TEXTURE_SWIZZLE_G = 0x8E43,
		TEXTURE_SWIZZLE_B = 0x8E44,
		TEXTURE_SWIZZLE_A = 0x8E45,
		TEXTURE_WRAP_S = 0x2802,
		TEXTURE_WRAP_T = 0x2803,
		TEXTURE_WRAP_R = 0x8072,
		IMAGE_FORMAT_COMPATIBILITY_TYPE = 0x90C7,
		TEXTURE_TARGET = 0x1006,
		TEXTURE_VIEW_MIN_LAYER = 0x82DD,
		TEXTURE_VIEW_MIN_LEVEL = 0x82DB,
		TEXTURE_VIEW_NUM_LAYERS = 0x82DE,
		TEXTURE_VIEW_NUM_LEVELS = 0x82DC,
/* /Textures.h */

/* TransformFeedback.h */
		TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
		TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
		TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
		TRANSFORM_FEEDBACK_PAUSED = 0x8E23,
		TRANSFORM_FEEDBACK_ACTIVE = 0x8E24,
		INTERLEAVED_ATTRIBS = 0x8C8C,
		SEPARATE_ATTRIBS = 0x8C8D,
/* /TransformFeedback.h */

/* Utility.h */
		VENDOR = 0x1F00,
		RENDERER = 0x1F01,
		VERSION = 0x1F02,
		SHADING_LANGUAGE_VERSION = 0x8B8C,
		EXTENSIONS = 0x1F03,
		NO_ERROR = 0,
		GUILTY_CONTEXT_RESET = 0x8253,
		INNOCENT_CONTEXT_RESET = 0x8254,
		UNKNOWN_CONTEXT_RESET = 0x8255,
		NUM_SAMPLE_COUNTS = 0x9380,
		SAMPLES = 0x80A9,
		INTERNALFORMAT_SUPPORTED = 0x826F,
		INTERNALFORMAT_PREFERRED = 0x8270,
		INTERNALFORMAT_RED_SIZE = 0x8271,
		INTERNALFORMAT_GREEN_SIZE = 0x8272,
		INTERNALFORMAT_BLUE_SIZE = 0x8273,
		INTERNALFORMAT_ALPHA_SIZE = 0x8274,
		INTERNALFORMAT_DEPTH_SIZE = 0x8275,
		INTERNALFORMAT_STENCIL_SIZE = 0x8276,
		INTERNALFORMAT_SHARED_SIZE = 0x8277,
		INTERNALFORMAT_RED_TYPE = 0x8278,
		INTERNALFORMAT_GREEN_TYPE = 0x8279,
		INTERNALFORMAT_BLUE_TYPE = 0x827A,
		INTERNALFORMAT_ALPHA_TYPE = 0x827B,
		INTERNALFORMAT_DEPTH_TYPE = 0x827C,
		INTERNALFORMAT_STENCIL_TYPE = 0x827D,
		MAX_WIDTH = 0x827E,
		MAX_HEIGHT = 0x827F,
		MAX_DEPTH = 0x8280,
		MAX_LAYERS = 0x8281,
		MAX_COMBINED_DIMENSIONS = 0x8282,
		COLOR_COMPONENTS = 0x8283,
		DEPTH_COMPONENTS = 0x8284,
		STENCIL_COMPONENTS = 0x8285,
		COLOR_RENDERABLE = 0x8286,
		DEPTH_RENDERABLE = 0x8287,
		STENCIL_RENDERABLE = 0x8288,
		FRAMEBUFFER_RENDERABLE = 0x8289,
		FRAMEBUFFER_RENDERABLE_LAYERED = 0x828A,
		FRAMEBUFFER_BLEND = 0x828B,
		READ_PIXELS = 0x828C,
		READ_PIXELS_FORMAT = 0x828D,
		READ_PIXELS_TYPE = 0x828E,
		TEXTURE_IMAGE_FORMAT = 0x828F,
		TEXTURE_IMAGE_TYPE = 0x8290,
		GET_TEXTURE_IMAGE_FORMAT = 0x8291,
		GET_TEXTURE_IMAGE_TYPE = 0x8292,
		MIPMAP = 0x8293,
		GENERATE_MIPMAP = 0x8191,
		AUTO_GENERATE_MIPMAP = 0x8295,
		COLOR_ENCODING = 0x8296,
		SRGB_READ = 0x8297,
		SRGB_WRITE = 0x8298,
		SRGB_DECODE_ARB = 0x8299,
		FILTER = 0x829A,
		VERTEX_TEXTURE = 0x829B,
		TESS_CONTROL_TEXTURE = 0x829C,
		TESS_EVALUATION_TEXTURE = 0x829D,
		GEOMETRY_TEXTURE = 0x829E,
		FRAGMENT_TEXTURE = 0x829F,
		COMPUTE_TEXTURE = 0x82A0,
		TEXTURE_SHADOW = 0x82A1,
		TEXTURE_GATHER = 0x82A2,
		TEXTURE_GATHER_SHADOW = 0x82A3,
		SHADER_IMAGE_LOAD = 0x82A4,
		SHADER_IMAGE_STORE = 0x82A5,
		SHADER_IMAGE_ATOMIC = 0x82A6,
		IMAGE_TEXEL_SIZE = 0x82A7,
		IMAGE_COMPATIBILITY_CLASS = 0x82A8,
		IMAGE_PIXEL_FORMAT = 0x82A9,
		IMAGE_PIXEL_TYPE = 0x82AA,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST = 0x82AC,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST = 0x82AD,
		SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE = 0x82AE,
		SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE = 0x82AF,
		TEXTURE_COMPRESSED_BLOCK_WIDTH = 0x82B1,
		TEXTURE_COMPRESSED_BLOCK_HEIGHT = 0x82B2,
		TEXTURE_COMPRESSED_BLOCK_SIZE = 0x82B3,
		CLEAR_BUFFER = 0x82B4,
		TEXTURE_VIEW = 0x82B5,
		VIEW_COMPATIBILITY_CLASS = 0x82B6,
		CLEAR_TEXTURE = 0x9365,
/* /Utility.h */

/* VertexArrayObject.h */
		VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D5,
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		VERTEX_ATTRIB_ARRAY_SIZE = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE = 0x8625,
		VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
		VERTEX_ATTRIB_ARRAY_INTEGER = 0x88FD,
		VERTEX_ATTRIB_ARRAY_DIVISOR = 0x88FE,
		CURRENT_VERTEX_ATTRIB = 0x8626,
/* /VertexArrayObject.h */
	};
}
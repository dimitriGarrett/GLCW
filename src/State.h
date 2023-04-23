#pragma once

#include "API.h"
#include "GLM.h"
#include "Config.h"

#include <vector>

#undef NO_ERROR

namespace GL
{
	enum class StateStrings : unsigned int
	{
		VENDOR = 0x1F00,
		RENDERER = 0x1F01,
		VERSION = 0x1F02,
		SHADING_LANGUAGE_VERSION = 0x8B8C
	};

	enum class BlendEquations : unsigned int
	{
		FUNC_ADD = 0x8006,
		FUNC_SUBTRACT = 0x800A,
		FUNC_REVERSE_SUBTRACT = 0x800B,
		MIN = 0x8007,
		MAX = 0x8008
	};

	enum class BlendFuncs : unsigned int
	{
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
		ONE_MINUS_CONSTANT_ALPHA = 0x8004
	};

#if VC(4, 5)
	enum class Clips : unsigned int
	{
		LOWER_LEFT = 0x8CA1,
		UPPER_LEFT = 0x8CA2
	};

	enum class ClipDepths : unsigned int
	{
		NEGATIVE_ONE_TO_ONE = 0x935E,
		ZERO_TO_ONE = 0x935F
	};
#endif

	enum class Faces : unsigned int
	{
		FRONT = 0x0404,
		BACK = 0x0405,
		FRONT_AND_BACK = 0x0408
	};

	enum class StateCompareFuncs : unsigned int
	{
		NEVER = 0x0200,
		LESS = 0x0201,
		EQUAL = 0x0202,
		LEQUAL = 0x0203,
		GREATER = 0x0204,
		NOTEQUAL = 0x0205,
		GEQUAL = 0x0206,
		ALWAYS = 0x0207
	};

	enum class StateEnables : unsigned int
	{
		BLEND = 0x0BE2,

#if GL_DESKTOP
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
#endif
		CULL_FACE = 0x0B44,
		DEPTH_TEST = 0x0B71,
		DITHER = 0x0BD0,
		POLYGON_OFFSET_FILL = 0x8037,
		RASTERIZER_DISCARD = 0x8C89,
		SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
		SAMPLE_COVERAGE = 0x80A0,
		SCISSOR_TEST = 0x0C11,
		STENCIL_TEST = 0x0B90,
		
#if VC(4, 3) || (!GL_DESKTOP)
		PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69,
#endif

#if VC(4, 3)
		DEBUG_OUTPUT = 0x92E0,
		DEBUG_OUTPUT_SYNCHRONOUS = 0x8242,
#endif
	};

	enum class FrontFaces : unsigned int
	{
		CW = 0x0900,
		CCW = 0x0901
	};

	enum class StateGets : unsigned int
	{
#if VC(4, 3)
		MAX_DEBUG_MESSAGE_LENGTH = 0x9143,
#endif

#if VC(4, 1)
		MAX_VIEWPORTS = 0x825B,
		VIEWPORT_SUBPIXEL_BITS = 0x825C,
		VIEWPORT_BOUNDS_RANGE = 0x825D,
		LAYER_PROVOKING_VERTEX = 0x825E,
		VIEWPORT_INDEX_PROVOKING_VERTEX = 0x825F,
#endif

#if VC(4, 2)
		MAX_TESS_CONTROL_ATOMIC_COUNTERS = 0x92D3,
		MAX_TESS_EVALUATION_ATOMIC_COUNTERS = 0x92D4,
		MAX_GEOMETRY_ATOMIC_COUNTERS = 0x92D5,
		MIN_MAP_BUFFER_ALIGNMENT = 0x90BC,
#endif

#if VC(4, 2) || EC(3, 1)
		MAX_FRAGMENT_ATOMIC_COUNTERS = 0x92D6,
		MAX_VERTEX_ATOMIC_COUNTERS = 0x92D2,
#endif

#if VC(4, 3) || EC(3, 1)
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
		PRIMITIVE_RESTART_FIXED_INDEX = 0x8D69,
		VERTEX_BINDING_DIVISOR = 0x82D6,
		VERTEX_BINDING_OFFSET = 0x82D7,
		VERTEX_BINDING_STRIDE = 0x82D8,
		MAX_VERTEX_ATTRIB_RELATIVE_OFFSET = 0x82D9,
		MAX_VERTEX_ATTRIB_BINDINGS = 0x82DA,
#endif

#if VC(4, 3)
		MAX_ELEMENT_INDEX = 0x8D6B,
		MAX_DEBUG_GROUP_STACK_DEPTH = 0x826C,
		DEBUG_GROUP_STACK_DEPTH = 0x826D,
		MAX_LABEL_LENGTH = 0x82E8,
		MAX_FRAMEBUFFER_LAYERS = 0x9317,
		MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS = 0x90D8,
		MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS = 0x90D9,
		MAX_GEOMETRY_SHADER_STORAGE_BLOCKS = 0x90D7,
		TEXTURE_BUFFER_OFFSET_ALIGNMENT = 0x919F,
#endif

#if GL_DESKTOP || EC(3, 1)
		MAX_COMBINED_ATOMIC_COUNTERS = 0x92D7,
		MAX_COMBINED_SHADER_STORAGE_BLOCKS = 0x90DC,
#endif

#if GL_DESKTOP
		ARRAY_BUFFER_BINDING = 0x889D,
		COLOR_LOGIC_OP = 0x0BF2,
		CONTEXT_FLAGS = 0x821E,
		DOUBLEBUFFER = 0x0C32,
		LINE_SMOOTH = 0x0B20,
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
		PROGRAM_POINT_SIZE = 0x8642,
		PROVOKING_VERTEX = 0x8E4F,
		POINT_SIZE = 0x0B11,
		POINT_SIZE_GRANULARITY = 0x0B13,
		POINT_SIZE_RANGE = 0x0B12,
		POLYGON_OFFSET_LINE = 0x2A02,
		POLYGON_OFFSET_POINT = 0x2A01,
		POLYGON_SMOOTH = 0x0B41,
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
		TIMESTAMP = 0x8E28,
		UNPACK_LSB_FIRST = 0x0CF1,
		UNPACK_SWAP_BYTES = 0x0CF0,
#else
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
		MAX_ELEMENT_INDEX = 0x8D6B,
		MAX_SAMPLES = 0x8D57,
		MAX_SHADER_STORAGE_BLOCK_SIZE = 0x90DE,
		MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
		MAX_VERTEX_ATTRIBS = 0x8869,
		RASTERIZER_DISCARD = 0x8C89,
		SAMPLE_ALPHA_TO_COVERAGE = 0x809E,
		SAMPLE_COVERAGE = 0x80A0,
		TRANSFORM_FEEDBACK_BINDING = 0x8E25,
		TRANSFORM_FEEDBACK_ACTIVE = 0x8E24,
		TRANSFORM_FEEDBACK_PAUSED = 0x8E23,
#endif

		ACTIVE_TEXTURE = 0x84E0,
		ALIASED_LINE_WIDTH_RANGE = 0x846E,
		BLEND = 0x0BE2,
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
		CULL_FACE = 0x0B44,
		CURRENT_PROGRAM = 0x8B8D,
		DEPTH_CLEAR_VALUE = 0x0B73,
		DEPTH_FUNC = 0x0B74,
		DEPTH_RANGE = 0x0B70,
		DEPTH_TEST = 0x0B71,
		DEPTH_WRITEMASK = 0x0B72,
		DITHER = 0x0BD0,
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
		POLYGON_OFFSET_FILL = 0x8037,
		POLYGON_OFFSET_UNITS = 0x2A00,
		PROGRAM_BINARY_FORMATS = 0x87FF,
		PROGRAM_PIPELINE_BINDING = 0x825A,
		READ_FRAMEBUFFER_BINDING = 0x8CAA,
		RENDERBUFFER_BINDING = 0x8CA7,
		SAMPLE_BUFFERS = 0x80A8,
		SAMPLE_COVERAGE_VALUE = 0x80AA,
		SAMPLE_COVERAGE_INVERT = 0x80AB,
		SAMPLER_BINDING = 0x8919,
		SAMPLES = 0x80A9,
		SCISSOR_BOX = 0x0C10,
		SCISSOR_TEST = 0x0C11,
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
		STENCIL_TEST = 0x0B90,
		STENCIL_VALUE_MASK = 0x0B93,
		STENCIL_WRITEMASK = 0x0B98,
		SUBPIXEL_BITS = 0x0D50,
		TEXTURE_BINDING_2D = 0x8069,
		TEXTURE_BINDING_2D_ARRAY = 0x8C1D,
		TEXTURE_BINDING_2D_MULTISAMPLE = 0x9104,
		TEXTURE_BINDING_3D = 0x806A,
		TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
		TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
		TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
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
	};

	enum class StateErrors : unsigned int
	{
		NO_ERROR = 0,
		INVALID_ENUM = 0x0500,
		INVALID_VALUE = 0x0501,
		INVALID_OPERATION = 0x0502,
		INVALID_FRAMEBUFFER_OPERATION = 0x0506,
		OUT_OF_MEMORY = 0x0505,

#if GL_DESKTOP
		STACK_UNDERFLOW = 0x0504,
		STACK_OVERFLOW = 0x0503
#endif
	};

	enum class StateHints : unsigned int
	{
#if GL_DESKTOP
		LINE_SMOOTH_HINT = 0x0C52,
		POLYGON_SMOOTH_HINT = 0x0C53,
		TEXTURE_COMPRESSION_HINT = 0x84EF,
#endif

		FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
#if (!GL_DESKTOP)
		GENERATE_MIPMAP_HINT = 0x8192,
#endif
	};

	enum class StateHintModes : unsigned int
	{
		FASTEST = 0x1101,
		NICEST = 0x1102,
		DONT_CARE = 0x1100
	};

	enum class StateLogics : unsigned int
	{
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
		OR_INVERTED = 0x150D
	};

	enum class StatePixelStores : unsigned int
	{
#if GL_DESKTOP
		PACK_SWAP_BYTES = 0x0D00,
		PACK_LSB_FIRST = 0x0D01,
		UNPACK_SWAP_BYTES = 0x0CF0,
		UNPACK_LSB_FIRST = 0x0CF1,
#endif

		PACK_ROW_LENGTH = 0x0D02,
		PACK_IMAGE_HEIGHT = 0x806C,
		PACK_SKIP_PIXELS = 0x0D04,
		PACK_SKIP_ROWS = 0x0D03,
		PACK_SKIP_IMAGES = 0x806B,
		PACK_ALIGNMENT = 0x0D05,
		
		
		UNPACK_ROW_LENGTH = 0x0CF2,
		UNPACK_IMAGE_HEIGHT = 0x806E,
		UNPACK_SKIP_PIXELS = 0x0CF4,
		UNPACK_SKIP_ROWS = 0x0CF3,
		UNPACK_SKIP_IMAGES = 0x806D,
		UNPACK_ALIGNMENT = 0x0CF5
	};

	enum class StatePointParameters : unsigned int
	{
		POINT_FADE_THRESHOLD_SIZE = 0x8128,
		POINT_SPRITE_COORD_ORIGIN = 0x8CA0
	};

	enum class StatePolygonModes : unsigned int
	{
		POINT = 0x1B00,
		LINE = 0x1B01,
		FILL = 0x1B02
	};

	enum class StateStencilOps : unsigned int
	{
		KEEP = 0x1E00,
		ZERO = 0,
		REPLACE = 0x1E01,
		INCR = 0x1E02,
		DECR = 0x1E03,
		INCR_WRAP = 0x8507,
		DECR_WRAP = 0x8508,
		INVERT = 0x150A
	};

	//glBlendColor — set the blend color
	GLCW_API void blendColor(float r, float g, float b, float a);
	//glBlendColor — set the blend color
	GLCW_API void blendColor(const glm::vec4& rgba);

	//glBlendEquation — specify the equation used for both the RGB blend equation and the Alpha blend equation
	GLCW_API void blendEquation(BlendEquations eq);

#if VC(4, 0)
	//glBlendEquation — specify the equation used for both the RGB blend equation and the Alpha blend equation
	GLCW_API void blendEquationi(unsigned int drawBuffer, BlendEquations eq);
#endif

	//glBlendEquationSeparate — set the RGB blend equation and the alpha blend equation separately
	GLCW_API void blendEquationSeperate(BlendEquations rgbMode, BlendEquations aMode);

#if VC(4, 0)
	//glBlendEquationSeparate — set the RGB blend equation and the alpha blend equation separately
	GLCW_API void blendEquationSeperatei(unsigned int drawBuffer, BlendEquations rgbMode, BlendEquations aMode);
#endif

	//glBlendFunc — specify pixel arithmetic
	GLCW_API void blendFunc(BlendFuncs sfactor, BlendFuncs dfactor);

#if VC(4, 0)
	//glBlendFunc — specify pixel arithmetic
	GLCW_API void blendFunci(unsigned int drawBuffer, BlendFuncs sfactor, BlendFuncs dfactor);
#endif

	//glBlendFuncSeparate — specify pixel arithmetic for RGB and alpha components separately
	GLCW_API void blendFuncSeparate(BlendFuncs srcRGB, BlendFuncs dstRGB, BlendFuncs srcAlpha, BlendFuncs dstAlpha);

#if VC(4, 0)
	//glBlendFuncSeparate — specify pixel arithmetic for RGB and alpha components separately
	GLCW_API void blendFuncSeparatei(unsigned int drawBuffer, BlendFuncs srcRGB, BlendFuncs dstRGB, BlendFuncs srcAlpha, BlendFuncs dstAlpha);
#endif

#if GL_DESKTOP
	//glClampColor — specify whether data read via glReadPixels should be clamped
	GLCW_API void clampColor(bool clamp);
#endif

#if VC(4, 5)
	//glClipControl — control clip coordinate to window coordinate behavior
	GLCW_API void clipControl(Clips origin, ClipDepths depth);
#endif

	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMask(bool red, bool green, bool blue, bool alpha);
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMask(const glm::bvec4& rgba);

#if GL_DESKTOP
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMaski(unsigned int drawBuffer, bool red, bool green, bool blue, bool alpha);
	//glColorMask, glColorMaski — enable and disable writing of frame buffer color components
	GLCW_API void colorMaski(unsigned int drawBuffer, const glm::bvec4& rgba);
#endif

	//glCullFace — specify whether front- or back-facing facets can be culled
	GLCW_API void cullFace(Faces cullMode);

	//glDepthFunc — specify the value used for depth buffer comparisons
	GLCW_API void depthFunc(StateCompareFuncs func);

	//glDepthMask — enable or disable writing into the depth buffer
	GLCW_API void depthMask(bool writeDepthToBuffer);

#if GL_DESKTOP
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRange(double near, double far);
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRange(const glm::dvec2& nearAndFar);
#endif

#if VC(4, 1) || (!GL_DESKTOP)
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRangef(float near, float far);
	//glDepthRange — specify mapping of depth values from normalized device coordinates to window coordinates
	GLCW_API void depthRangef(const glm::fvec2& nearAndFar);
#endif

#if VC(4, 1)
	//glDepthRangeArray — specify mapping of depth values from normalized device coordinates to window coordinates for a specified set of viewports
	GLCW_API void depthRangeArrayv(unsigned int first, int count, const std::vector<double>& values);

	//glDepthRangeIndexed — specify mapping of depth values from normalized device coordinates to window coordinates for a specified viewport
	GLCW_API void depthRangeIndexed(unsigned int index, double nearVal, double farVal);
	//glDepthRangeIndexed — specify mapping of depth values from normalized device coordinates to window coordinates for a specified viewport
	GLCW_API void depthRangeIndexed(unsigned int index, const glm::vec2& nearAndFar);
#endif

	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void enable(StateEnables cap);
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void disable(StateEnables cap);

#if GL_DESKTOP
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void enablei(StateEnables cap, unsigned int index);
	//glEnable — enable or disable server-side GL capabilities
	GLCW_API void disablei(StateEnables cap, unsigned int index);
#endif

	//glFrontFace — define front- and back-facing polygons
	GLCW_API void frontFace(FrontFaces mode);

	//glGet — return the value or values of a selected parameter
	GLCW_API void getBooleanv(StateGets pname, unsigned char* values);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API void getDoublev(StateGets pname, double* values);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API void getFloatv(StateGets pname, float* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getIntegerv(StateGets pname, int* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getInteger64v(StateGets pname, signed long long* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getBooleani_v(StateGets target, unsigned int index, unsigned char* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getIntegeri_v(StateGets target, unsigned int index, int* values);
	//glGet — return the value or values of a selected parameter
	GLCW_API void getFloati_v(StateGets target, unsigned int index, float* values);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API void getDoublei_v(StateGets target, unsigned int index, double* values);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API void getInteger64i_v(StateGets target, unsigned int index, signed long long* values);

	//glGet — return the value or values of a selected parameter
	GLCW_API bool getBooleanv(StateGets pname);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API double getDoublev(StateGets pname);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API float getFloatv(StateGets pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API int getIntegerv(StateGets pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API signed long long getInteger64v(StateGets pname);
	//glGet — return the value or values of a selected parameter
	GLCW_API bool getBooleani_v(StateGets target, unsigned int index);
	//glGet — return the value or values of a selected parameter
	GLCW_API int getIntegeri_v(StateGets target, unsigned int index);
	//glGet — return the value or values of a selected parameter
	GLCW_API float getFloati_v(StateGets target, unsigned int index);
#if GL_DESKTOP
	//glGet — return the value or values of a selected parameter
	GLCW_API double getDoublei_v(StateGets target, unsigned int index);
#endif
	//glGet — return the value or values of a selected parameter
	GLCW_API signed long long getInteger64i_v(StateGets target, unsigned int index);

	//glGetError — return error information
	GLCW_API StateErrors getError();

	//glHint — specify implementation-specific hints
	GLCW_API void hint(StateHints target, StateHintModes mode);

	//glIsEnabled, glIsEnabledi — test whether a capability is enabled
	GLCW_API bool isEnabled(StateEnables cap);
#if GL_DESKTOP
	//glIsEnabled, glIsEnabledi — test whether a capability is enabled
	GLCW_API bool isEnabledi(StateEnables cap, unsigned int index);
#endif
	//glLineWidth — specify the width of rasterized lines
	GLCW_API void lineWidth(float width);

#if GL_DESKTOP
	//glLogicOp — specify a logical pixel operation for rendering
	GLCW_API void logicOp(StateLogics opcode);

	//glPixelStore — set pixel storage modes
	GLCW_API void pixelStoref(StatePixelStores pname, float param);
#endif
	//glPixelStore — set pixel storage modes
	GLCW_API void pixelStorei(StatePixelStores pname, int param);

#if GL_DESKTOP
	//glPointParameter — specify point parameters
	GLCW_API void pointParameterf(StatePointParameters pname, float param);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameteri(StatePointParameters pname, int param);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameterfv(StatePointParameters pname, const float* params);
	//glPointParameter — specify point parameters
	GLCW_API void pointParameteriv(StatePointParameters pname, const int* params);

	//glPointSize — specify the diameter of rasterized points
	GLCW_API void pointSize(float size);

	//glPolygonMode — select a polygon rasterization mode
	GLCW_API void polygonMode(StatePolygonModes mode);
#endif

	//glPolygonOffset — set the scale and units used to calculate depth values
	GLCW_API void polygonOffset(float factor, float units);

	//glSampleCoverage — specify multisample coverage parameters
	GLCW_API void sampleCoverage(float value, bool invert);

	//glScissor — define the scissor box
	GLCW_API void scissor(int x, int y, int width, int height);
	//glScissor — define the scissor box
	GLCW_API void scissor(const glm::ivec4& xYWidthHeight);

#if GL_DESKTOP
	//glScissorArray — define the scissor box for multiple viewports
	GLCW_API void scissorArrayv(unsigned int first, int count, const std::vector<int>& values);

	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexed(unsigned int index, int left, int bottom, int width, int height);
	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexed(unsigned int index, const glm::ivec4& leftBottomWidthHeight);
	//glScissorIndexed — define the scissor box for a specific viewport
	GLCW_API void scissorIndexedv(unsigned int index, const std::vector<int>& values);
#endif

	//glStencilFunc — set front and back function and reference value for stencil testing
	GLCW_API void stencilFunc(StateCompareFuncs func, int ref, unsigned int mask);

	//glStencilFuncSeparate — set front and/or back function and reference value for stencil testing
	GLCW_API void stencilFuncSeparate(Faces face, StateCompareFuncs func, int ref, unsigned int mask);

	//glStencilMask — control the front and back writing of individual bits in the stencil planes
	GLCW_API void stencilMask(unsigned int mask);

	//glStencilMaskSeparate — control the front and/or back writing of individual bits in the stencil planes
	GLCW_API void stencilMaskSeparate(Faces face, unsigned int mask);

	//glStencilOp — set front and back stencil test actions
	GLCW_API void stencilOp(StateStencilOps sfail, StateStencilOps dpfail, StateStencilOps dppass);

	//glStencilOpSeparate — set front and/or back stencil test actions
	GLCW_API void stencilOpSeparate(Faces face, StateStencilOps sfail, StateStencilOps dpfail, StateStencilOps dppass);

	//glViewport — set the viewport
	GLCW_API void viewport(int x, int y, int width, int height);
	//glViewport — set the viewport
	GLCW_API void viewport(const glm::ivec4& xYWidthHeight);

#if VC(4, 1)
	//glViewportArray — set multiple viewports
	GLCW_API void viewportArrayv(unsigned int first, int count, const std::vector<float>& values);

	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedf(unsigned int index, float x, float y, float width, float height);
	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedf(unsigned int index, const glm::vec4& xYWidthHeight);
	//glViewportIndexed — set a specified viewport
	GLCW_API void viewportIndexedfv(unsigned int index, const std::vector<float>& values);
#endif
}
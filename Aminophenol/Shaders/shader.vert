
#version 450

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 vertexUV;

layout(push_constant) uniform PushConstant
{
	vec3 offset;
	vec3 color;
} pushConstant;

layout(location = 0) out vec3 fragColor;

void main()
{
	gl_Position = vec4(vertexPosition + pushConstant.offset, 1.0);
	fragColor = pushConstant.color;
}

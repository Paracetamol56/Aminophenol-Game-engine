
#version 450

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec2 vertexUV;

layout(push_constant) uniform PushConstant
{
	mat4 modelTransform;
} pushConstant;

layout(location = 0) out vec3 fragColor;

void main()
{
	gl_Position = vec4(vertexPosition, 1.0) * pushConstant.modelTransform;
	fragColor = vertexColor;
}

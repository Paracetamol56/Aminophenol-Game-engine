
#version 450

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in vec3 vertexNormal;
layout(location = 3) in vec2 vertexUV;

layout(set = 0, binding = 0) uniform CameraUBO
{
	mat4 viewMatrix;
	mat4 projectionMatrix;
} cameraUBO;

layout(push_constant) uniform PushConstant
{
	mat4 modelMatrix;
	mat4 normalMatrix;
} pushConstant;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec3 fragPositionWorld;
layout(location = 2) out vec3 fragNormalWorld;
layout(location = 3) out vec2 fragUV;

void main()
{
	vec4 positionWorld = vec4(vertexPosition, 1.0) * pushConstant.modelMatrix;
	gl_Position = positionWorld * cameraUBO.viewMatrix * cameraUBO.projectionMatrix;
	fragColor = vertexColor;
	fragPositionWorld = positionWorld.xyz;
	fragNormalWorld = normalize(vertexNormal * mat3(pushConstant.normalMatrix));
	fragUV = vertexUV;
}

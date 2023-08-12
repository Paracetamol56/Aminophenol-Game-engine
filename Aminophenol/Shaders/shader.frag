
#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec3 fragPositionWorld;
layout(location = 2) in vec3 fragNormalWorld;

layout(location = 0) out vec4 color;

struct SunLight
{
	vec3 direction;
	vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

const SunLight sunLight = SunLight(
	normalize(vec3(0.0, -1.0, 0.0)),
	vec3(0.1, 0.1, 0.1),
	vec3(0.5, 0.5, 0.5),
	vec3(0.8, 0.8, 0.8),
    32.0
);

void main()  
{
	vec3 fragToLightDir = normalize(-sunLight.direction); // Direction from fragment to light
    vec3 normal = normalize(fragNormalWorld);
    vec3 viewDir = normalize(-vec3(0.0, 0.0, 1.0)); // Assuming camera is looking along negative z-axis

    // Ambient component
    vec3 ambient = sunLight.ambient * fragColor;

    // Diffuse component
    float diffIntensity = max(dot(normal, fragToLightDir), 0.0);
    vec3 diffuse = sunLight.diffuse * diffIntensity * fragColor;

    // Specular component
    vec3 reflectionDir = reflect(-fragToLightDir, normal);
    float specIntensity = pow(max(dot(reflectionDir, viewDir), 0.0), sunLight.shininess); // Specular power
    vec3 specular = sunLight.specular * specIntensity;

    // Final color with Phong illumination
    color = vec4(ambient + diffuse + specular, 1.0);
}

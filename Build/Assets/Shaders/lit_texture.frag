#version 430

#define POINT		0
#define DIRECTIONAL 1
#define SPOT		2

in layout(location = 0) vec3 fposition;
in layout(location = 1) vec3 fnormal;
in layout(location = 2) vec2 ftexcoord;

out layout(location = 0) vec4 ocolor;

layout(binding = 0) uniform sampler2D tex;

uniform struct Material
{
	vec3 diffuse;
	vec3 specular;
	float shininess;

	vec2 offset;
	vec2 tiling;
} material;

uniform vec3 ambientLight;

uniform struct Light
{
	int type;
	vec3 position;
	vec3 direction;
	vec3 color;
	float intensity;
	float range;
	float innerAngle;
	float outerAngle;
} light;

vec3 ads(in vec3 position, in vec3 normal)
{
	// AMBIENT
	vec3 a = ambientLight;

	// ATTENUATION
	float attenuation = 1;
	if (light.type != DIRECTIONAL)
	{
		float distanceSqr = dot(light.position - position, light.position - position);
		float rangeSqr = pow(light.range, 2.0);
		attenuation = max(0, 1 - pow((distanceSqr / rangeSqr), 2.0));
		attenuation = pow(attenuation, 2.0);
	}

	// DIFFUSE
	vec3 lightDir = (light.type == DIRECTIONAL) ? normalize(-light.direction) : normalize(light.position - position);

	float spotIntensity = 1;
	if (light.type == SPOT)
	{
		float angle = acos(dot(light.direction, -lightDir));
		spotIntensity = smoothstep(light.outerAngle + 0.001, light.innerAngle, angle);
	}

	float intensity = max(dot(lightDir, normal), 0) * spotIntensity;
	vec3 d = material.diffuse * (light.color * intensity) * light.intensity;

	// SPECULAR
	vec3 s = vec3(0);
	if (intensity > 0)
	{
		vec3 reflection = reflect(-lightDir, normal);
		vec3 viewDir = normalize(-position);
		intensity = max(dot(reflection, viewDir), 0);
		intensity = pow(intensity, material.shininess);
		s = material.specular * intensity * spotIntensity  * light.intensity;
	}

	return a + (d + s) * light.intensity * attenuation;
}

void main()
{
	vec4 texcolor = texture(tex, ftexcoord);
	ocolor = texcolor * vec4(ads(fposition, fnormal), 1);
}
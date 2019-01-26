#version 330 core

struct Light {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};
in vec3 fragPos; // координаты точки
in vec3 fragNorm; // координаты нормали в точке

out vec4 color;

uniform Material material;uniform Light light; // компоненты света
uniform vec3 lightPos; // координаты источника света

uniform Light light_static; // компоненты дополнительного света
uniform vec3 light_staticPos; // координаты дополнительного источника света

uniform vec3 viewPos; // координаты точки наблюдения

void main() {
	// нормализуем полученный вектор нормали
	vec3 norm = normalize(fragNorm);
	// получаем нормализованный вектор направления на источник света
	vec3 lightDir = normalize(lightPos - fragPos);
	// вычисляем косинус угла между полученными векторами
	float cosTheta = max(dot(norm, lightDir), 0.0);

	float powOfCos; // коэффициент бликовой освещенности
	if (cosTheta > 0.0) { // если cosTheta <= 0, бликовая освещенность равна 0
		// получаем нормализованный вектор направления в точку наблюдения
		vec3 viewDir = normalize(viewPos - fragPos);
		// получаем вектор отраженного света
		vec3 lightDirR = reflect(-lightDir, norm);
		powOfCos = pow(max(dot(viewDir, lightDirR), 0.0), material.shininess);
	}
	else
		powOfCos = 0.0;

	vec3 ambient = light.ambient * material.ambient;
	vec3 diffuse = light.diffuse * cosTheta * material.diffuse;
	vec3 specular = light.specular * powOfCos * material.specular;

	vec3 result = ambient + diffuse + specular;

	// дополнительный источник света
	// получаем нормализованный вектор направления на источник света
	lightDir = normalize(light_staticPos - fragPos);
	// вычисляем косинус угла между полученными векторами
	cosTheta = max(dot(norm, lightDir), 0.0);

	if (cosTheta > 0.0) { // если cosTheta <= 0, бликовая освещенность равна 0
		// получаем нормализованный вектор направления в точку наблюдения
		vec3 viewDir = normalize(viewPos - fragPos);
		// получаем вектор отраженного света
		vec3 lightDirR = reflect(-lightDir, norm);
		powOfCos = pow(max(dot(viewDir, lightDirR), 0.0), material.shininess);
	}
	else
		powOfCos = 0.0;

	ambient = light_static.ambient * material.ambient;
	diffuse = light_static.diffuse * cosTheta * material.diffuse;
	specular = light_static.specular * powOfCos * material.specular;

	result += ambient + diffuse + specular;
	color = vec4(result, 1.0);
}
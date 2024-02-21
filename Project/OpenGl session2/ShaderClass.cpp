#include "ShaderClass.h"

std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);

	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg()); 
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close(); 
		return(contents); 
	}

}

ShaderClass::ShaderClass(const char* vertexfile, const char* fragmentfile)
{
		std::string vertexCode = get_file_contents(vertexfile);
	std::string fragmentCode = get_file_contents(fragmentfile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	//compile shaders

	//vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	//fragment shader
	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentshader);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentshader);

	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentshader);

}

void ShaderClass::Activate()
{
	glUseProgram(ID);
}

void ShaderClass::DeleteShader()
{
		glDeleteProgram(ID);
}

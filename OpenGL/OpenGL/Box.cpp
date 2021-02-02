////#include <glm/glm.hpp>
////#include <glm/gtc/matrix_transform.hpp>
////#include <glm/gtc/type_ptr.hpp>
////
////#include <Shader.h>
////#include <iostream>
////
//// GLEW
////#define GLEW_STATIC
////#include <GL/glew.h>
//// GLFW
////#include <GLFW/glfw3.h>
////#define STB_IMAGE_IMPLEMENTATION
////#include "stb_image.h"
////
//// Window dimensions
////const GLuint WIDTH = 800, HEIGHT = 600;
////
//// The MAIN function, from here we start the application and run the game loop
////int main()
////{
////
////
////	glfwInit();
////	 Set all the required options for GLFW
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
////
////	 Create a GLFWwindow object that we can use for GLFW's functions
////	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
////	if (window == nullptr)
////	{
////		std::cout << "Failed to create GLFW window" << std::endl;
////		glfwTerminate();
////		return -1;
////	}
////	glfwMakeContextCurrent(window);
////
////	 Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
////	glewExperimental = GL_TRUE;
////	 Initialize GLEW to setup the OpenGL Function pointers
////	if (glewInit() != GLEW_OK)
////	{
////		std::cout << "Failed to initialize GLEW" << std::endl;
////		return -1;
////	}
////
////	 Define the viewport dimensions
////	int width, height;
////	glfwGetFramebufferSize(window, &width, &height);
////	glViewport(0, 0, width, height);
////
////	 Build and compile our shader program
////	Shader ourShader("shader/Box/v.vs", "shader/Box/f.fs");
////
////	float vertices[] = {
////
////	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
////	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
////	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
////	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
////	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
////	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
////
////	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
////	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
////	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
////	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
////	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
////	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
////
////	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
////	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
////	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////
////	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
////	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
////	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////
////	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
////	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
////	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
////	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
////	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
////
////	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
////	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
////	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
////	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
////	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
////	};
////
////	glm::vec3 cubePositions[] = {
////		glm::vec3(0.0f,  0.0f,  0.0f),
////		glm::vec3(2.0f,  5.0f, -15.0f),
////		glm::vec3(-1.5f, -2.2f, -2.5f),
////		glm::vec3(-3.8f, -2.0f, -12.3f),
////		glm::vec3(2.4f, -0.4f, -3.5f),
////		glm::vec3(-1.7f,  3.0f, -7.5f),
////		glm::vec3(1.3f, -2.0f, -2.5f),
////		glm::vec3(1.5f,  2.0f, -2.5f),
////		glm::vec3(1.5f,  0.2f, -1.5f),
////		glm::vec3(-1.3f,  1.0f, -1.5f)
////	};
////
////	GLuint VBO, VAO;
////	glGenVertexArrays(1, &VAO);
////	glGenBuffers(1, &VBO);
////
////	glBindVertexArray(VAO);
////
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////
////	 Position attribute
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
////	glEnableVertexAttribArray(0);
////	 TexCoord attribute
////	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
////	glEnableVertexAttribArray(2);
////
////	glBindVertexArray(0); // Unbind VAO
////		
////	 
////	 Load and create a texture 
////	GLuint texture;
////	glGenTextures(1, &texture);
////	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
////	 Set the texture wrapping parameters
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
////	 Set texture filtering parameters
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////	 Load image, create texture and generate mipmaps
////
////	 加载并生成纹理
////	int nrChannels;
////	unsigned char *data = stbi_load("wall.jpg", &width, &height, &nrChannels, 0);
////	if (data)
////	{
////		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
////		glGenerateMipmap(GL_TEXTURE_2D);
////	}
////	else
////	{
////		std::cout << "Failed to load texture" << std::endl;
////	}
////	stbi_image_free(data);
////
////	glEnable(GL_DEPTH_TEST);
////
////	 Game loop
////	while (!glfwWindowShouldClose(window))
////	{
////		 Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
////		glfwPollEvents();
////
////		 Render
////		 Clear the colorbuffer
////		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
////		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
////		 Bind Textures using texture units
////		glBindTexture(GL_TEXTURE_2D, texture);
////
////		 Activate shader
////		ourShader.Use();
////
////		 Create transformations
////		glm::mat4 view;
////		glm::mat4 projection;
////		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
////		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
////		 Get their uniform location
////		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
////		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
////		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
////		 Pass the matrices to the shader
////		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
////		 Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
////		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
////
////		glBindVertexArray(VAO);
////		for (GLuint i = 0; i < 10; i++)
////		{
////			 Calculate the model matrix for each object and pass it to shader before drawing
////			glm::mat4 model;
////			model = glm::translate(model, cubePositions[i]);
////			model = glm::rotate(model, (GLfloat)glfwGetTime() * (i+1) * 10, glm::vec3(1.0f, 0.3f, 0.5f));
////			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
////			glDrawArrays(GL_TRIANGLES, 0, 36);
////		}
////
////		glBindVertexArray(0);
////
////		 Swap the screen buffers
////		glfwSwapBuffers(window);
////	}
////	 Properly de-allocate all resources once they've outlived their purpose
////	glDeleteVertexArrays(1, &VAO);
////	glDeleteBuffers(1, &VBO);
////	 Terminate GLFW, clearing any resources allocated by GLFW.
////	glfwTerminate();
////
////	 Terminate GLFW, clearing any resources allocated by GLFW.
////	glfwTerminate();
////	return 0;
////}
////

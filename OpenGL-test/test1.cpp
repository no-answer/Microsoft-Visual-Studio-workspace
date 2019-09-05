#include<iostream>
#include <glad/glad.h>
#include <glfw3.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height)//����Ǵ��ڱ仯�Ļص���������ע���������
																		 //��һ��glfw�Ĵ��ڣ�һ����Ⱥ͸߶�
{
	glViewport(0, 0, width, height);//����ǻص������ڵ�����
									//�����ǽ��ӿڸĳɱ仯��ĵĴ��ڴ�С
									//ע����Ҫ��ע��ûص�����
									//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
									//���������ǣ�glfw�Ĵ����Լ��ص�����
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//��ȡ�������������esc 
		glfwSetWindowShouldClose(window, true);//����ǿ�ƴ���Ӧ�ùر�
}
int main()
{
	glfwInit();//������֮ǰ��gluinitһ����ÿⶼ��Ҫ���г�ʼ��
			   //�汾����opengl4.5
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//�������汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);//���ôΰ汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);//��macϵͳ����Ҫ���ø����
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);//��������������������ʾ���͹���ģ�
																			   //һ��⺯������ض��壬
																			   //�������ú��Ժ�ֱ�Ӳ鿴������ϸ�Ķ���
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		system("pause");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))//�ڵ���opengl����֮ǰ��ʼ��glad��
															//glad�����þ��ǿ��ٵĽ�opengl����ӳ�䵽��ص��Կ�������
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glViewport(0, 0, 800, 600);//�����ӿڴ�С
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//ע�ắ�����ú���������ע���������Ӳ���Ļص�����
																	  //
																	  //��Ⱦ����
	while (!glfwWindowShouldClose(window))//���glfw�����Ƿ�ָ��Ҫ��رգ�����ǵĻ�������˳�ѭ��
	{

		//�������ز���
		processInput(window);//



							 // ��Ⱦ����ز���

		glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//�鿴���е��¼������ҽ����ڴ�
		glfwSwapBuffers(window);//������ɫ���棬��glfw�����ڵ����ݡ�����ע��glfw��ͷ�Ľ����ͺ���gl��ͷ������
		glfwPollEvents();//����Ƿ��������Ĵ���ʱ�䣬���������Ĵ��ڴ�С�仯����Ҫ������صĻص�����
	}
	glfwTerminate();//����˳�
	return 0;
}
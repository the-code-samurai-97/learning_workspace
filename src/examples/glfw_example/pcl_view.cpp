//
// Created by sibi on 12/3/23.
//
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
struct Point {
    float x, y, z;
};
// Function to set up GLFW window and OpenGL context
GLFWwindow* initializeGLFW() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Point Cloud Viewer", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    return window;
}

// Function to render the point cloud
void renderPointCloud(const pcl::PointCloud<pcl::PointXYZ>& pointCloud) {
    glPointSize(2.0F);
    glBegin(GL_POINTS);

    for (const auto& point : pointCloud.points) {
        glVertex3f(point.x, point.y, point.z);
    }

    glEnd();
}

int main(int argc , char *argv[]) {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // Load point cloud from a .pcd file
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) == -1) {
        std::cerr << "Couldn't read the point cloud file" << std::endl;
        return -1;
    }
    std::vector<Point> pointCloud = {
            {0.0f, 0.0f, 0.0f},
            {1.0f, 0.0f, 0.0f},
            {0.0f, 1.0f, 0.0f},
            // Add more points as needed
    };
    GLFWwindow* window = initializeGLFW();
    if (!window) {
        return -1;
    }
    // Enable color blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//    // Main loop
    while (!glfwWindowShouldClose(window)) {
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPointSize(100.0F);
        glBegin(GL_POINTS);


        for (const auto& point : pointCloud) {
            glColor3ub(255.0,1.0,0.0);
            glVertex3f(point.x, point.y, point.z);
        }

        glEnd();
//        // Swap front and back buffers
        glfwSwapBuffers(window);
//
//        // Poll for and process events
        glfwPollEvents();
    }
//
    // Terminate GLFW
    glfwTerminate();

    return 0;
}

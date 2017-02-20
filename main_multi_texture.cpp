//Team members Anupa Prudhvi, Geethanjali Jeevanatham, Arko Basu, Sindhusha Dhulipala



// stl include
#include <iostream>
#include <string>

// GLEW include
#include <GL/glew.h>

// GLM include files
#define GLM_FORCE_INLINE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>


// glfw includes
#include <GLFW/glfw3.h>


// include local files
#include "controls.h"
#include "HCI557Common.h"
#include "CoordSystem.h"
#include "Plane3D.h"
#include "Texture.h"
#include "Box3D.h"
#include "Sphere3D.h"
#include "GLObjectObj.h"
#include "Box3D112.h"
#include "GLSphere.h"




using namespace std;


// The handle to the window object
GLFWwindow*         window;

// Define some of the global variables we're using for this sample
GLuint program;

/* A trackball to move and rotate the camera view */
extern Trackball trackball;


// this is a helper variable to allow us to change the texture blend model
extern int g_change_texture_blend;


glm::mat4 model_matrix2 = glm::mat4();
glm::mat4 model_matrix1 = glm::mat4();
glm::mat4 model_matrix3 = glm::mat4();
glm::mat4 model_matrix4 = glm::mat4();
glm::mat4 model_matrix5 = glm::mat4();
glm::mat4 model_matrix6 = glm::mat4();
glm::mat4 model_matrix7 = glm::mat4();
glm::mat4 model_matrix8 = glm::mat4();
glm::mat4 model_matrix9 = glm::mat4();
glm::mat4 model_matrix10 = glm::mat4();


glm::mat4 model_matrixt1 = glm::mat4();
glm::mat4 model_matrixt2 = glm::mat4();
glm::mat4 model_matrixt3 = glm::mat4();
glm::mat4 model_matrixt4 = glm::mat4();
glm::mat4 model_matrixt5 = glm::mat4();
glm::mat4 model_matrixt6 = glm::mat4();
glm::mat4 model_matrixt7 = glm::mat4();
glm::mat4 model_matrixt8 = glm::mat4();
glm::mat4 model_matrixt9 = glm::mat4();
glm::mat4 model_matrixt10 = glm::mat4();
glm::mat4 model_matrixt11 = glm::mat4();

glm::mat4 model_matrixplane = glm::mat4();

glm::mat4 model_matrixsphere1 = glm::mat4();
glm::mat4 model_matrixsphere2 = glm::mat4();

glm::mat4 model_matrixload1 = glm::mat4();


// angle of rotation for the camera direction
float angle=0.0,angle1=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f,ly=0.0f;
// XZ position of the camera
float x=0.0f,z=1000.0f, y=400.0f;
float fraction = 10.0f;
int i = 0;

void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    bool move = false;
    
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    // Translation
    if( (key == 87 && action == GLFW_REPEAT) || (key == 87 && action == GLFW_PRESS) ) // key w
    {
        x += lx * fraction;
        z += lz * fraction;
    }
    else if((key == 83 && action == GLFW_REPEAT) || (key == 83 && action == GLFW_PRESS)) // key s
    {
        x -= lx * fraction;
        z -= lz * fraction;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    // Rotation
    if((key == 65 && action == GLFW_REPEAT)||( key == 65 && action == GLFW_PRESS)) // key a
    {
        angle -= 0.4f;
        lx = sin(angle);
        lz = -cos(angle);
    }
    
    else if((key == 68 && action == GLFW_REPEAT) || (key == 68 && action == GLFW_REPEAT)) // key d
    {
        angle += 0.4f;
        lx = sin(angle);
        lz = -cos(angle);
    }
    else if((key == 77 && action == GLFW_REPEAT) || (key == 77 && action == GLFW_REPEAT)){
        
        if(i==0){
        glm::mat4 translationp11 = glm::translate(glm::vec3(-1300.0, 400.0, 270.0));
        //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
        glm::mat4 rotationp112 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
        glm::mat4 translationp111 = glm::translate(glm::vec3(1000.0, -400.0, 0.0));
        model_matrixplane = translationp11 * rotationp112 * translationp111;
            i = 1;
        }
        else if(i==1){
            i = 0;
            glm::mat4 translationp11 = glm::translate(glm::vec3(-1000.0, 400.0, 0.0));
            //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
            glm::mat4 rotationp112 = glm::rotate( 1.5f, glm::vec3(0.0, -1.0, 0.0));
            glm::mat4 translationp111 = glm::translate(glm::vec3(1000.0, -400.0, 0.0));
            model_matrixplane = translationp11  * translationp111;
            

        }

    }
    else if((key == 71 && action == GLFW_REPEAT) || (key == 71 && action == GLFW_PRESS)) // key s
    {
        y += ly * fraction;
    }
    else if((key == 72 && action == GLFW_REPEAT) || (key == 72 && action == GLFW_PRESS)) // key s
    {
        y -= ly * fraction;
    }
       SetViewAsLookAt(glm::vec3(x, y, z), glm::vec3(x+lx, y+ly,  z+lz), glm::vec3(0.0f, 1.0f, 0.0f));
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //cout << key << endl;
}



void frame0(){
    //glm::mat4 model_matrix2 = glm::mat4(); //box_3
    glm::mat4 translation2 = glm::translate(glm::vec3(-875.0, 370.0, -510.0));
    glm::mat4 rotation2 = glm::rotate( 0.37f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    
    //glm::mat4 model_matrix1 = glm::mat4(); //box_4
    glm::mat4 translation = glm::translate(glm::vec3(-885.0, 270.0, -490.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    
    //glm::mat4 model_matrix3 = glm::mat4(); //box_1
    glm::mat4 translation3 = glm::translate(glm::vec3(-619.0, 370.0, -700.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(0.57f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    
    // glm::mat4 model_matrix4 = glm::mat4(); //box_2
    glm::mat4 translation4 = glm::translate(glm::vec3(-570.0, 270.0, -700.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(0.57f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    
    // glm::mat4 model_matrix5 = glm::mat4(); //box_9
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -600.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    
    //glm::mat4 model_matrix6 = glm::mat4(); //box_0
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-600));
    glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    
    //glm::mat4 model_matrix7 = glm::mat4(); //box_5
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    
    // glm::mat4 model_matrix8 = glm::mat4(); //box_6
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    
    //glm::mat4 model_matrix9 = glm::mat4(); //box_7
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    
    // glm::mat4 model_matrix10 = glm::mat4(); //box_8
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame1(){
    //glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-875.0, 370.0, -510.0));
    glm::mat4 rotation2 = glm::rotate( 0.37f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    //glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-885.0, 270.0, -490.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-619.0, 370.0, -700.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(0.57f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    //glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-570.0, 270.0, -700.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(0.57f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    //glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -600.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    //glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-600));
    glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -530.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7 * translation17;
    
    //glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    //glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame2(){
    //glm::mat4 model_matrix2 = glm::mat4(); //box_3
    glm::mat4 translation2 = glm::translate(glm::vec3(-770.0, 370.0, -340.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    //glm::mat4 model_matrix1 = glm::mat4(); //box_4
    glm::mat4 translation = glm::translate(glm::vec3(-760.0, 270.0, -330.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.50f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    // glm::mat4 model_matrix3 = glm::mat4(); //box_1
    glm::mat4 translation3 = glm::translate(glm::vec3(-740.0, 370.0, -675.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    // glm::mat4 model_matrix4 = glm::mat4(); //box_2
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, -700.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.50f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    //glm::mat4 model_matrix5 = glm::mat4(); //box_9
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -500.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    // glm::mat4 model_matrix6 = glm::mat4(); //box_0
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-500));
    glm::mat4 rotation6 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //glm::mat4 model_matrix7 = glm::mat4(); //box_5
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    // glm::mat4 model_matrix8 = glm::mat4(); //box_6
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    // glm::mat4 model_matrix9 = glm::mat4(); //box_7
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
}

void frame3(){
    // glm::mat4 model_matrix2 = glm::mat4(); //box_3
    glm::mat4 translation2 = glm::translate(glm::vec3(-770.0, 370.0, -340.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    // glm::mat4 model_matrix1 = glm::mat4(); //box_4
    glm::mat4 translation = glm::translate(glm::vec3(-760.0, 270.0, -330.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.50f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //  glm::mat4 model_matrix3 = glm::mat4(); //box_1
    glm::mat4 translation3 = glm::translate(glm::vec3(-740.0, 370.0, -675.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    // glm::mat4 model_matrix4 = glm::mat4(); //box_2
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, -700.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.50f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    // glm::mat4 model_matrix5 = glm::mat4(); //box_9
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -500.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    // glm::mat4 model_matrix6 = glm::mat4(); //box_0
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-500));
    glm::mat4 rotation6 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    // glm::mat4 model_matrix7 = glm::mat4(); //box_5
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //  glm::mat4 model_matrix8 = glm::mat4(); //box_6
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //  glm::mat4 model_matrix9 = glm::mat4(); //box_7
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -430.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame4(){
    // glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-620.0, 370.0, -310.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    //  glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-600.0, 270.0, -310.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    // glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-890.0, 370.0, -500.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    //  glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-890.0, 270.0, -540.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    // glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -400.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    //  glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-400));
    glm::mat4 rotation6 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    // glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //  glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //  glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
}

void frame5(){
    // glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-620.0, 370.0, -310.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    //  glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-600.0, 270.0, -310.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    // glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-890.0, 370.0, -500.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    //  glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-890.0, 270.0, -540.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    // glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -400.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    //  glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-400));
    glm::mat4 rotation6 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    // glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -330.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7 *translation17;
    
    //  glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //  glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
}

void frame6(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-580.0, 270.0, -320.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -300.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-910.0, 270.0, -320.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -300.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-300));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
}

void frame7(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(0.57f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-570.0, 280.0, -370.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -300.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(0.57f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-920.0, 280.0, -370.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -300.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-300));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -230.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
}

void frame8(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(1.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 390.0, -300.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -200.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(1.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 390.0, -300.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -200.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-200));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -200.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame9(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(2.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 460.0, -250.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(2.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -200.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(2.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 460.0, -250.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(2.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -200.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-200));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -130.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame10(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(3.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 460.0, -40.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(3.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -100.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(3.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 460.0, -40.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(3.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -100.0));
    //glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-100));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -100.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -100.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame11(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, -100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(5.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, -80.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(5.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, -100.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(5.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, -80.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(5.5f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -100.0));
    //glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750,320,-100));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, -40.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, -100.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
    
}

void frame12(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 0.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, -20.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 0.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, -20.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 0.0));
    //glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,0.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 0.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 0.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame13(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 0.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, -10.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 0.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, -10.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 0.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,0.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 0.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 70.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame14(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, 150.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 100.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, 150.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 100.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 100.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame15(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, 150.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 100.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, 170.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 100.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 170.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame16(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 280.0, 240.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 200.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 280.0, 250.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 200.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 200.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 200.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame17(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(7.0f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 300.0, 270.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 200.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(7.0f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-940.0, 280.0, 170.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(0.40f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 200.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 200.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 270.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame18(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 340.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.0f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 300.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-940.0, 270.0, 340.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.20f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 300.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 300.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame19(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 340.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.0f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 300.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-940.0, 270.0, 340.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.20f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 300.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.57f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 370.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * rotation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
    
}

void frame20(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(7.0f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 370.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(0.40f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 400.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(7.0f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 290.0, 480.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 400.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.57f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 400.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 400.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame21(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(7.0f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 370.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(0.40f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 400.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(7.0f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 290.0, 480.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 400.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.57f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 400.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 470.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame22(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 550.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 500.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 290.0, 550.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 500.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 500.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame23(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 550.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 500.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 290.0, 550.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 500.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 570.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame24(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-580.0, 370.0, 600.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-560.0, 270.0, 650.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-910.0, 370.0, 600.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-930.0, 290.0, 650.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation34 = glm::rotate(1.60f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,600.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 600.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7    * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 600.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame25(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-620.0, 370.0, 710.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-590.0, 280.0, 800.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 0.5f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation31 * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-880.0, 370.0, 500.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.5f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-950.0, 270.0, 540.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(0.3f, glm::vec3(0.0,0.0,-1.0));
    glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4 * rotation34 * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,600.0));
    glm::mat4 rotation6 = glm::rotate( 2.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 600.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7    * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 670.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame26(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-790.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-790.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 700.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7    * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-690.0, 170.0, 700.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9    * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-690.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * translation110;
    
    
}

void frame27(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-790.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-790.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-815.0, 170.0, 725.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-815.0, 60.0, 725.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-710.0, 170.0, 680.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-710.0, 60.0, 680.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
    
}

void frame28(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-790.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-790.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-750.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
}

void frame29(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-740.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-760.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-750.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
    
}

void frame30(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-700.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-750.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82 * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
}

void frame31(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-700.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-680.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation82 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8  * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
}

void frame32(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-740.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-700.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-760.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-680.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation82 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8  * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-680.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
    
}

void frame33(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-650.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-590.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-590.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-650.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82  * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92    * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
    
}

void frame34(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-650.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-590.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-590.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-650.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8 * rotation82  * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92    * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10 * rotation102 * translation110;
    
    
}

void frame35(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-650.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-590.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-590.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-650.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame36(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-650.0, 370.0, 880.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2 * rotation32 * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-590.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, -1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3 * rotation33 *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-590.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,-1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-580.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-550.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame37(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-640.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-630.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-450.0, 370.0, 550.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-410.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-550.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-550.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-550.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-550.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-480.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92    * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame38(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-540.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-530.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, 550.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-450.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 2.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-450.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-450.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-450.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-450.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame39(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-540.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-530.0, 270.0, 890.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, 550.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.0f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-450.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-450.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.0f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-380.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-450.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame40(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-350.0, 370.0, 860.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-300.0, 270.0, 880.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, 550.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-350.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-350.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-350.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-350.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-350.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame41(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-350.0, 370.0, 860.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-300.0, 270.0, 880.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, 550.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, 520.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-350.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-350.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-350.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-350.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-350.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame42(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-240.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-170.0, 270.0, 820.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-460.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-410.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-350.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-350.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-350.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-280.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   *  rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame43(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-140.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-70.0, 270.0, 820.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-360.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-310.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-250.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.0f, glm::vec3(0.0, -1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-250.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-250.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-250.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-250.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame44(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-140.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-70.0, 270.0, 820.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-360.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-310.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-250.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 0.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-250.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-180.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-250.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame45(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-40.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(30.0, 270.0, 820.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-260.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-220.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-150.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-150.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-150.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-150.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9     * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-150.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame46(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-40.0, 370.0, 830.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(30.0, 270.0, 820.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-260.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-220.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-150.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-150.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-150.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-80.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame47(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(60.0, 370.0, 810.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(140.0, 270.0, 790.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-160.0, 370.0, 580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-120.0, 270.0, 510.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(2.3f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-50.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-50.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 2.3f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-50.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-50.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-50.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame48(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-50.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(30.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-50.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(30.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-50.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-50.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-50.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-50.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-50.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame49(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-50.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(30.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-50.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(30.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-50.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-50.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(30.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-50.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame50(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(50.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(80.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(50.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(80.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(50.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(50.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(50.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(50.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(50.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame51(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(50.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(80.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(50.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(80.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(50.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(50.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(50.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(130.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame52(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(150.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(180.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(150.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(180.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(150.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(150.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(150.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(150.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(150.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame53(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(150.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(180.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(150.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(180.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(150.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(150.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(230.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(150.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame54(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(250.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(280.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(250.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(280.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(250.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(250.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(250.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(250.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(250.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame55(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(250.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(280.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(250.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(280.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(250.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(250.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(250.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(330.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(350.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame56(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(350.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(380.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(350.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(380.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(350.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(350.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(350.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(350.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(350.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame57(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(350.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(380.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(350.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(380.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(350.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(350.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(350.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(350.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(430.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame58(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(450.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(480.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(450.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(480.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(450.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(450.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(450.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(450.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(450.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame59(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(450.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(480.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(450.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(480.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(450.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(450.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(530.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(550.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(450.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(450.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame60(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(550.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(580.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(550.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(580.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(550.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(550.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(550.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(550.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(550.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(550.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame61(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(550.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(580.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(550.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(580.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(550.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(550.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(550.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(550.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(630.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame62(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(650.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(680.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(680.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(650.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(650.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame63(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(650.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(680.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(650.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(680.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(650.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(650.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(730.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(650.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(650.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame64(){
    
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(750.0, 370.0, 870.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(780.0, 270.0, 870.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(750.0, 370.0, 530.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(780.0, 270.0, 530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(1.6f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(750.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame65(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 700.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 670.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 720.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 670.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 1.6f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(750.0, 170.0, 760.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(750.0, 60.0, 760.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(750.0, 170.0, 640.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(750.0, 60.0, 640.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame66(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 700.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 670.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 720.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 670.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 700.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 700.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame67(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 700.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 670.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 720.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 670.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,700.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 630.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 700.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame68(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 600.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 570.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 620.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 570.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,600.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 600.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 600.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame69(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 600.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 570.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 620.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 570.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,600.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 600.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 530.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 *  rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame70(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 470.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 520.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 470.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 500.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 500.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame71(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 470.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 520.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 470.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 500.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 430.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame72(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 370.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 420.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 370.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 400.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 400.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 400.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
}

void frame73(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 370.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 420.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 370.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 400.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 400.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 330.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame74(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 270.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 320.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 270.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 300.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 300.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame75(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 270.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 320.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 270.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 300.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 230.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 *  rotation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame76(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 170.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 220.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 170.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 200.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 200.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 200.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame77(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 170.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 220.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 170.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 200.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 200.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 130.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame78(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 70.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 120.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 70.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 100.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 100.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame79(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, 70.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 120.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, 70.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 100.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 30.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame80(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 0.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -30.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 20.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -30.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 0.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,0.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 0.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, 0.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame81(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, 0.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -30.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, 20.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -30.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, 0.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,0.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, 0.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -70.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame82(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -130.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -80.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -130.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -100.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -100.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame83(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -100.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -130.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -80.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -130.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -100.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-100.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -170.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -100.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -100.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame84(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -230.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -180.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -230.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -200.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -200.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -200.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame85(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -200.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -230.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -180.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -230.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -200.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-200.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -200.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -200.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -270.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame86(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -330.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -280.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -330.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -300.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -300.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame87(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -300.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -330.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -280.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -330.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -300.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-300.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -370.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -300.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -300.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame88(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -430.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -380.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -430.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -400.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -400.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -400.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9   * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame89(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -400.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -430.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -380.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -430.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -400.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-400.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -400.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -400.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -470.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame90(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -530.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -480.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -500.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -500.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame91(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -500.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -530.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -480.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -530.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -500.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-500.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -570.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -500.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -500.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame92(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -600.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -630.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -630.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-600.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -600.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -600.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame93(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -600.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -630.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -580.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -630.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -600.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-600.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -600.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -600.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -670.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation9 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame94(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(910.0, 370.0, -700.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(910.0, 270.0, -630.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(590.0, 370.0, -680.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(590.0, 270.0, -730.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(3.2f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 3.2f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(815.0, 170.0, -700.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(815.0, 60.0, -700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(685.0, 170.0, -700.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(685.0, 60.0, -700.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame95(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(730.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(700.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(750.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(700.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(750.0, 170.0, -765.0));
    glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(750.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(750.0, 170.0, -635.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(750.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame96(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(730.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(700.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(750.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(700.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(750.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(750.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(670.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(650.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(750.0, 170.0, -635.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(750.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame97(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(630.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(600.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(650.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(600.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(650.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(650.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(650.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(650.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(650.0, 170.0, -635.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(650.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame98(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(630.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(600.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(650.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(600.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(650.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(650.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(650.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(650.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(570.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(550.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame99(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(530.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(500.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(550.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(500.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(550.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(550.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(550.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(550.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(550.0, 170.0, -635.0));
    glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(550.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame100(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(530.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(500.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(550.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(500.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(550.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(550.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(470.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(450.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(550.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(550.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame101(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(430.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(400.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(450.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(400.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(450.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(450.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(450.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(450.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(450.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(450.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame102(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(430.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(400.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(450.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(400.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(450.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(450.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(450.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(450.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(370.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(350.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame103(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(330.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(300.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(350.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(300.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(350.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(350.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(350.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(350.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(350.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(350.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame104(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(330.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(300.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(350.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(300.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(350.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(350.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(270.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(350.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(350.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame105(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(230.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(200.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(250.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(200.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(250.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(250.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(250.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(250.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(250.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame106(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(230.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(200.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(250.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(200.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(250.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(250.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(250.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(250.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(170.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame107(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(130.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(100.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(150.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(100.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(150.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(150.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(150.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(150.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(150.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame108(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(130.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(100.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(150.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(100.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(150.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(150.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(70.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(150.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(150.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame109(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(30.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(0.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(50.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(0.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(50.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(50.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(50.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(50.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(50.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame110(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(30.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(0.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(50.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(0.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(50.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(50.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(50.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(50.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-20.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
    
}

void frame111(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-30.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-100.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-50.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-100.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-50.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-50.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-50.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-50.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-50.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame112(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-30.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-100.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-50.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-100.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-50.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-50.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6 * rotation6 * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-120.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-50.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-50.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame113(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-130.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-200.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-150.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-200.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-150.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-150.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-150.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-150.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-150.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
    
}

void frame114(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-130.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-200.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-150.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-200.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-150.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-150.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-150.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-150.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-220.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame115(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-230.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-300.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-250.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-250.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-250.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-250.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-250.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-250.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame116(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-230.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-300.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-250.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-300.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-250.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-250.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-320.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72 * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-250.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-250.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
    
}

void frame117(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-330.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-400.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-400.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-350.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-350.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-350.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-350.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-350.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame118(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-330.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-400.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-350.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-400.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-350.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-350.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-350.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-350.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-420.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame119(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-430.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-500.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-450.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-500.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-450.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-450.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-450.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-450.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-450.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame120(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-430.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-500.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-450.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-500.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-450.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-450.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-520.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-550.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-450.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-450.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame121(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-530.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-600.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-550.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-600.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-550.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-550.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-550.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-550.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-550.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-550.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame122(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-530.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-600.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-550.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-600.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-550.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-550.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-550.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-550.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-620.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame123(){
    
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-630.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-700.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-650.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-650.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
}

void frame124(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-630.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-700.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-650.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-700.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-650.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-650.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-720.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7 * rotation72  * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-650.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-650.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame125(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-730.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-800.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-750.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-800.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-750.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-750.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-750.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame126(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-730.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-800.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-750.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-800.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-750.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-750.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-750.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-750.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-820.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9 * rotation92 * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-850.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}

void frame127(){
    //   glm::mat4 model_matrix2 = glm::mat4(); //box_3 right arm
    glm::mat4 translation2 = glm::translate(glm::vec3(-830.0, 370.0, -855.0));
    glm::mat4 rotation2 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 rotation22 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 rotation32 = glm::rotate(6.2f, glm::vec3(1.0,0.0,0.0));
    glm::mat4 translation12 = glm::translate(glm::vec3(905.0, -370.0, 800.0));
    model_matrix2 = translation2  * rotation22 * rotation2 * translation12;
    
    //    glm::mat4 model_matrix1 = glm::mat4(); //box_4 right hand
    glm::mat4 translation = glm::translate(glm::vec3(-900.0, 270.0, -875.0));
    glm::mat4 rotation = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation21 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    //glm::mat4 rotation31 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation1 = glm::translate(glm::vec3(905.0, -270.0, 800.0));
    model_matrix1 = translation * rotation21 * rotation * translation1;
    
    //    glm::mat4 model_matrix3 = glm::mat4(); //box_1 left arm
    glm::mat4 translation3 = glm::translate(glm::vec3(-850.0, 370.0, -525.0));
    glm::mat4 rotation3 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, 1.0));
    glm::mat4 rotation23 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    glm::mat4 rotation33 = glm::rotate(6.2f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation13 = glm::translate(glm::vec3(595.0, -370.0, 800.0));
    model_matrix3 = translation3  *rotation23 * rotation3 * translation13;
    
    //     glm::mat4 model_matrix4 = glm::mat4(); //box_2 left hand
    glm::mat4 translation4 = glm::translate(glm::vec3(-900.0, 270.0, -495.0));
    glm::mat4 rotation4 = glm::rotate( 1.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation24 = glm::rotate(4.8f, glm::vec3(0.0,1.0,0.0));
    //glm::mat4 rotation34 = glm::rotate(0.57f, glm::vec3(-1.0,0.0,0.0));
    glm::mat4 translation14 = glm::translate(glm::vec3(595.0, -270.0, 800.0));
    model_matrix4 = translation4  * rotation24 * rotation4 * translation14;
    
    
    //    glm::mat4 model_matrix5 = glm::mat4(); //box_9 head
    glm::mat4 translation5 = glm::translate(glm::vec3(-850.0, 460.0, -700.0));
    glm::mat4 rotation5 = glm::rotate( 0.0f, glm::vec3(-1.0, 0.0, 0.0));
    glm::mat4 rotation51 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation15 = glm::translate(glm::vec3(750.0, -460.0, 800.0));
    model_matrix5 = translation5  * rotation51 * rotation5 * translation15;
    
    
    //    glm::mat4 model_matrix6 = glm::mat4(); //box_0 torso
    glm::mat4 translation6 = glm::translate(glm::vec3(-850.0,320.0,-700.0));
    glm::mat4 rotation6 = glm::rotate( 4.8f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translation16 = glm::translate(glm::vec3(750.0, -320.0, 800.0));
    model_matrix6 = translation6  * translation16;
    
    //    glm::mat4 model_matrix7 = glm::mat4(); //box_5 right thigh
    glm::mat4 translation7 = glm::translate(glm::vec3(-850.0, 170.0, -765.0));
    //glm::mat4 rotation7 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation72 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation17 = glm::translate(glm::vec3(815.0, -170.0, 800.0));
    model_matrix7 = translation7   * translation17;
    
    //   glm::mat4 model_matrix8 = glm::mat4(); //box_6 right leg
    glm::mat4 translation8 = glm::translate(glm::vec3(-850.0, 60.0, -765.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation82 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation18 = glm::translate(glm::vec3(815.0, -60.0, 800.0));
    model_matrix8 = translation8   * translation18;
    
    //    glm::mat4 model_matrix9 = glm::mat4(); //box_7 left thigh
    glm::mat4 translation9 = glm::translate(glm::vec3(-850.0, 170.0, -635.0));
    //glm::mat4 rotation9 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation92 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation19 = glm::translate(glm::vec3(690.0, -170.0, 800.0));
    model_matrix9 = translation9  * translation19;
    
    //   glm::mat4 model_matrix10 = glm::mat4(); //box_8 left leg
    glm::mat4 translation10 = glm::translate(glm::vec3(-850.0, 60.0, -635.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    glm::mat4 rotation102 = glm::rotate( 0.57f, glm::vec3(0.0, 0.0, -1.0));
    glm::mat4 translation110 = glm::translate(glm::vec3(690.0, -60.0, 800.0));
    model_matrix10 = translation10  * translation110;
    
    
    
}





int main(int argc, const char * argv[])
{
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Init glfw, create a window, and init glew
    
    // Init the GLFW Window
    window = initWindow();
    
    
    // Init the glew api
    initGlew();
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Create some models
    
    // coordinate system
    CoordSystem* cs = new CoordSystem(40.0);
    
    
    // create an apperance object.
    GLAppearance* apperance_0 = new GLAppearance("../../data/shaders/texture_filter.vs", "../../data/shaders/texture_filter.fs");
    
    GLAppearance* apperance_1 = new GLAppearance("../../data/shaders/noise_map.vs", "../../data/shaders/noise_map.fs");
    
    GLAppearance* apperance_2 = new GLAppearance("../../data/shaders/displacement_texture.vs", "../../data/shaders/displacement_texture.fs");
    
    GLAppearance* apperance_3 = new GLAppearance("../../data/shaders/spherical_mapping.vs", "../../data/shaders/spherical_mapping.fs");
    
    GLAppearance* apperance_4 = new GLAppearance("../../data/shaders/multi_texture.vs", "../../data/shaders/multi_texture.fs");
    
    GLAppearance* apperance_7 = new GLAppearance("../../data/shaders/multi_vertex_lights.vs", "../../data/shaders/multi_vertex_lights.fs");
    
    GLAppearance* apperance_5 = new GLAppearance("../../data/shaders/displacement_texture1.vs", "../../data/shaders/displacement_texture1.fs");
    
    GLAppearance* apperance_6 = new GLAppearance("../../data/shaders/spherical_mapping1.vs", "../../data/shaders/spherical_mapping1.fs");
    
    GLAppearance* apperance_8 = new GLAppearance("../../data/shaders/displacement_texture.vs", "../../data/shaders/displacement_texture.fs");
    
    GLAppearance* apperance_9 = new GLAppearance("../../data/shaders/single_texture.vs", "../../data/shaders/single_texture.fs");
    
    GLAppearance* apperance_10 = new GLAppearance("../../data/shaders/multi_vertex_lights.vs", "../../data/shaders/multi_vertex_lights.fs");
    
    GLDirectLightSource  light_sourceload;
    light_sourceload._lightPos = glm::vec4(20.0,20.0,0.0, 0.0);
    light_sourceload._ambient_intensity = 0.2;
    light_sourceload._specular_intensity = 5.5;
    light_sourceload._diffuse_intensity = 2.0;
    light_sourceload._attenuation_coeff = 0.0;
    
    // add the light to this apperance object
    apperance_10->addLightSource(light_sourceload);
    
    // Create a material object
    GLMaterial material_load;
    material_load._diffuse_material = glm::vec3(1.0, 0.0, 0.2);
    material_load._ambient_material = glm::vec3(1.0, 0.0, 0.2);
    material_load._specular_material = glm::vec3(1.0, 1.0, 1.0);
    material_load._shininess = 12.0;
    material_load._transparency = 1.0;
    
    // Add the material to the apperance object
    apperance_10->setMaterial(material_load);
    apperance_10->finalize();

    
    
    GLDirectLightSource  light_source;
    light_source._lightPos = glm::vec4(600.0, 600.0, 600.0, 0.0);
    light_source._ambient_intensity = 0.2;
    light_source._specular_intensity = 4.5;
    light_source._diffuse_intensity = 1.0;
    light_source._attenuation_coeff = 0.0;
    
    // add the light to this apperance object
    apperance_0->addLightSource(light_source);
    apperance_3->addLightSource(light_source);
    apperance_5->addLightSource(light_source);
    apperance_6->addLightSource(light_source);
    
    GLSpotLightSource spotlight_source;
    spotlight_source._lightPos = glm::vec4(0.0, 100.0, 50.0, 1.0);
    spotlight_source._ambient_intensity = 0.2;
    spotlight_source._specular_intensity = 30.5;
    spotlight_source._diffuse_intensity = 8.0;
    spotlight_source._attenuation_coeff = 0.0002;
    spotlight_source._cone_direction = glm::vec3(-1.0, -1.0, -1.0);
    spotlight_source._cone_angle = 60.0;
    
    apperance_0->addLightSource(spotlight_source);
    apperance_3->addLightSource(spotlight_source);
    apperance_5->addLightSource(spotlight_source);
    apperance_6->addLightSource(light_source);
    
    
    
    GLDirectLightSource  light_source_1;
    light_source_1._lightPos = glm::vec4(-1500.0, 1000.0, 0.0, 0.0);
    light_source_1._ambient_intensity = 0.2;
    light_source_1._specular_intensity = 50.5;
    light_source_1._diffuse_intensity = 500.0;
    light_source_1._attenuation_coeff = 0.0;
    
    // add the light to this apperance object
    apperance_1->addLightSource(light_source_1);
    apperance_7->addLightSource(light_source_1);
    apperance_8->addLightSource(light_source_1);
    apperance_9->addLightSource(light_source_1);
    
    GLSpotLightSource spotlight_source_1;
    spotlight_source_1._lightPos = glm::vec4(-2250.0, 800.0, 1100.0, 1.0);
    spotlight_source_1._ambient_intensity = 0.8;
    spotlight_source_1._specular_intensity = 10.0;
    spotlight_source_1._diffuse_intensity = 1000.0;
    spotlight_source_1._attenuation_coeff = 0.0002;
    spotlight_source_1._cone_direction = glm::vec3(-1.0, -1.0, -1.0);
    spotlight_source_1._cone_angle = 180.0;
    
    apperance_1->addLightSource(spotlight_source_1);
    apperance_7->addLightSource(spotlight_source_1);
    apperance_8->addLightSource(spotlight_source_1);
    apperance_9->addLightSource(spotlight_source_1);
    
    // Create a material object
    GLMaterial material_1;
    material_1._diffuse_material = glm::vec3(0.0, 0.0, 1.0);
    material_1._ambient_material = glm::vec3(0.0, 0.0, 1.0);
    material_1._specular_material = glm::vec3(0.0, 0.0, 1.0);
    material_1._shininess = 12.0;
    material_1._transparency = 1.0;
    
    // Add the material to the apperance object
    apperance_1->setMaterial(material_1);
    apperance_7->setMaterial(material_1);
    apperance_8->setMaterial(material_1);
    apperance_9->setMaterial(material_1);
    
    GLSpotLightSource spotlight_source_2;
    spotlight_source_2._lightPos = glm::vec4(-1750.0, 1200.0, -400.0, 1.0);
    spotlight_source_2._ambient_intensity = 0.2;
    spotlight_source_2._specular_intensity = 10.0;
    spotlight_source_2._diffuse_intensity = 1000.0;
    spotlight_source_2._attenuation_coeff = 0.0002;
    spotlight_source_2._cone_direction = glm::vec3(-1.0, -1.0, -1.0);
    spotlight_source_2._cone_angle = 180.0;
    
    apperance_8->addLightSource(spotlight_source_2);
    
    // Create a material object
    GLMaterial material_2;
    material_2._diffuse_material = glm::vec3(0.0, 1.0, 0.0);
    material_2._ambient_material = glm::vec3(0.0, 1.0, 0.0);
    material_2._specular_material = glm::vec3(0.0, 1.0, 0.0);
    material_2._shininess = 12.0;
    material_2._transparency = 1.0;
    
    // Add the material to the apperance object
    apperance_8->setMaterial(material_2);
    
    
    
    // Create a material object
    GLMaterial material_0;
    material_0._diffuse_material = glm::vec3(0.8, 0.8, 0.0);
    material_0._ambient_material = glm::vec3(0.8, 0.8, 0.0);
    material_0._specular_material = glm::vec3(1.0, 1.0, 1.0);
    material_0._shininess = 12.0;
    material_0._transparency = 1.0;
    
    // Add the material to the apperance object
    apperance_0->setMaterial(material_0);
    apperance_3->setMaterial(material_0);
    apperance_5->setMaterial(material_0);
    apperance_6->setMaterial(material_0);
    
    
    
    
    //************************************************************************************************
    // Add a texture
    // Add a texture
    GLTexture* texture = new GLTexture();
    int texid = texture->loadAndCreateTexture("../../data/textures1/textured-paper.bmp");
    GLTexture* tex11 = texture;
    apperance_0->setTexture(texture);
    //apperance_0->finalize();
    
    GLTexture* texture1 = new GLTexture();
    int texid1 = texture1->loadAndCreateTexture("../../data/textures1/old_wood_floor_v1_512x512.bmp");
    GLTexture* tex22 = texture1;
    
    
    GLTexture* texture2 = new GLTexture();
    int texid2 = texture2->loadAndCreateTexture("../../data/textures1/wooden-door-with-sandblasted-glass.bmp");
    GLTexture* tex33 = texture2;
    apperance_0->setTexture(texture2);
    
    
    GLTexture* texture3 = new GLTexture();
    int texid3 = texture3->loadAndCreateTexture("../../data/textures1/stone_texture.bmp");
    GLTexture* tex4 = texture3;
    apperance_0->setTexture(texture3);
    
    // Add a texture for displacement mapping
    GLMultiTexture* texture_multi1 = new GLMultiTexture();
    int texid_multi1 = texture_multi1->loadAndCreateTextures("../../data/textures1/textured-paper.bmp", "../../data/textures1/textured-paper.bmp");
    // apperance_1->setTexture(texture_multi1);
    
    // Add a texture for bump mapping
    GLMultiTexture* texture_bump = new GLMultiTexture();
    int texid_bump = texture_bump->loadAndCreateTextures("../../data/textures1/Stone_wall_texture_sketchup_warehouse_type071.bmp", "../../data/maps/texture_brick_NRM.bmp");
    // apperance_2->setTexture(texture_bump);
    
    // Add a texture for bump mapping
    // Add a texture for Environmental mapping
    GLTexture* texture_disp = new GLTexture();
    int texid_disp = texture_disp->loadAndCreateTexture("../../data/textures1/plain_plaster_texture_02_by_goodtextures-d2y1pz6.bmp");
    
    // Add a texture for Environmental mapping
    GLTexture* texture_env = new GLTexture();
    int texid_env = texture_env->loadAndCreateTexture("../../data/textures1/leonid-afremov-paintings-2.bmp");
    //apperance_3->setTexture(texture_env);
    
    // Add a texture for displacement mapping
    GLMultiTexture* texture_multi2 = new GLMultiTexture();
    int texid_multi2 = texture_multi2->loadAndCreateTextures("../../data/textures1/textured-paper.bmp", "../../data/textures1/fresko2_NRM.bmp");
    // apperance_4->setTexture(texture_multi2);
    
    
    
    GLTexture* texturea2 = new GLTexture();
    int texida2 = texturea2->loadAndCreateTexture("../../data/textures1/tekstura-fon-metallik.bmp");
    
    GLTexture* texturea3 = new GLTexture();
    int texida3 = texturea3->loadAndCreateTexture("../../data/textures1/wood_texture_2_by_annfrost_stock.bmp");
    
    GLTexture* texturea4 = new GLTexture();
    int texida4 = texturea4->loadAndCreateTexture("../../data/textures1/wall_paiting_2.bmp");
    
    GLTexture* texturea5 = new GLTexture();
    int texida5 = texturea5->loadAndCreateTexture("../../data/textures1/wall_paiting_1.bmp");
    
    GLTexture* texturea6 = new GLTexture();
    int texida6 = texturea6->loadAndCreateTexture("../../data/textures1/textured-paper.bmp");
    
    GLTexture* texturea7 = new GLTexture();
    int texida7 = texturea7->loadAndCreateTexture("../../data/textures1/194_1orange_peel.bmp");
    
    GLTexture* texturea8 = new GLTexture();
    int texida8 = texturea8->loadAndCreateTexture("../../data/textures1/tileable-basket-weave-textures-1-2.bmp");
    
    glm::vec3 A = glm::vec3(55.0, 130.0, 100.0);
    glm::vec3 B = glm::vec3(70.0, 130.0, 100.0);
    glm::vec3 C = glm::vec3(130.0, 130.0, 100.0);
    glm::vec3 D = glm::vec3(145.0, 130.0, 100.0);
    glm::vec3 E = glm::vec3(117.0, 70.0, 100.0);
    glm::vec3 F = glm::vec3(117.0, 30.0, 100.0);
    glm::vec3 G = glm::vec3(83.0, 30.0, 100.0);
    glm::vec3 H = glm::vec3(83.0, 70.0, 100.0);
    glm::vec3 I = glm::vec3(55.0, 100.0, 100.0);
    glm::vec3 J = glm::vec3(145.0, 100.0, 100.0);
    glm::vec3 K = glm::vec3(100.0, 145.0, 100.0);
    glm::vec3 L = glm::vec3(100.0, 130.0, 100.0);
    glm::vec3 M = glm::vec3(100.0, 100.0, 100.0);
    glm::vec3 N = glm::vec3(100.0, 70.0, 100.0);
    
    
    
    
    //model_matrix7 = translation7 * translation17;
    
    // create the sphere geometry
    
    
    
  /*  glm::mat4 translationload1 = glm::translate(glm::vec3(-2000.0, 0.0, 0.0));
    //glm::mat4 rotation6 = glm::rotate( 0.57f, glm::vec3(1.0, 0.0, 0.0));
    //glm::mat4 rotationload1 = glm::rotate( 1.5f, glm::vec3(0.0, 1.0, 0.0));
    glm::mat4 translationload11 = glm::translate(glm::vec3(2000.0, 0.0, 0.0));
    
    model_matrixload1 = translationload1 * translationload11; */
    
    GLSphere3D* sphere3 = new GLSphere3D(12.5, 397.5, -12.5, 12.5, 500, 500);
    sphere3->setApperance(*apperance_6);
    sphere3->init();
    
    GLSphere3D* sphere4 = new GLSphere3D(-12.5, 397.5, -12.5, 12.5, 500, 500);
    sphere4->setApperance(*apperance_6);
    sphere4->init();
    
    GLSphere3D* sphere5 = new GLSphere3D(0.0, 410.0, 0.0, 12.5, 500, 500);
    sphere5->setApperance(*apperance_6);
    sphere5->init();
    
    GLSphere3D* sphere1 = new GLSphere3D(-12.5, 397.5, 12.5, 12.5, 500, 500);
    sphere1->setApperance(*apperance_6);
    sphere1->init();
    
    GLSphere3D* sphere2 = new GLSphere3D(12.5, 397.5, 12.5, 12.5, 500, 500);
    sphere2->setApperance(*apperance_6);
    sphere2->init();
    
    GLBox3D112* h1 = new GLBox3D112();
    h1->setApperance(*apperance_9);
    h1->init();
    
    GLBox3D* box0 = new GLBox3D(-750.0, 320.0, -800.0, 250, 200, 100, 500, 500);
    box0->setApperance(*apperance_0);
    box0->init();
    //box_0->setMatrix(model_matrix6);
    
    GLBox3D* box1 = new GLBox3D(-595.0, 370.0, -800.0, 60, 100, 100, 500, 500);
    box1->setApperance(*apperance_0);
    box1->init();
    //box_1->setMatrix(model_matrix3);
    
    GLBox3D* box2 = new GLBox3D(-595.0, 245.0, -800.0, 45, 150, 85, 500, 500);
    box2->setApperance(*apperance_0);
    box2->init();
    //box_2->setMatrix(model_matrix4);
    
    GLBox3D* box3 = new GLBox3D(-905.0, 370.0, -800.0, 60, 100, 100, 500, 500);
    box3->setApperance(*apperance_0);
    box3->init();
    //box_3->setMatrix(model_matrix2);
    
    GLBox3D* box4 = new GLBox3D(-905.0, 245.0, -800.0, 45, 150, 85, 500, 500);
    box4->setApperance(*apperance_0);
    box4->init();
    // box_4->setMatrix(model_matrix1);
    
    GLBox3D* box5 = new GLBox3D(-815.0, 170.0, -800.0, 100, 100, 100, 500, 500);
    box5->setApperance(*apperance_0);
    box5->init();
    // box_5->setMatrix(model_matrix7);
    
    GLBox3D* box6 = new GLBox3D(-815.0, 60.0, -800.0, 90, 120, 85, 500, 500);
    box6->setApperance(*apperance_0);
    box6->init();
    // box_6->setMatrix(model_matrix8);
    
    GLBox3D* box7 = new GLBox3D(-690.0, 170.0, -800.0, 100, 100, 100, 500, 500);
    box7->setApperance(*apperance_0);
    box7->init();
    //  box_7->setMatrix(model_matrix9);
    
    GLBox3D* box8 = new GLBox3D(-690.0, 60.0, -800.0, 90, 120, 85, 500, 500);
    box8->setApperance(*apperance_0);
    box8->init();
    // box_8->setMatrix(model_matrix10);
    
    
    GLBox3D* box9 = new GLBox3D(-750.0, 460.0, -800.0, 80, 80, 100, 500, 500);
    box9->setApperance(*apperance_0);
    box9->init();
    // box_9->setMatrix(model_matrix5);
    
    GLPlane3D* plane_0 = new GLPlane3D(500.0, 500.0, 2000.0, 1000.0, 1000.0, 1);
    plane_0->setApperance(*apperance_0);
    plane_0->init();
    
    GLPlane3D* plane_1 = new GLPlane3D(0.0, 500.0, 1500.0, 1000.0, 1000.0, 2);
    plane_1->setApperance(*apperance_0);
    plane_1->init();
    
    GLPlane3D* plane_2 = new GLPlane3D(1000.0, 500.0, 500.0, 3000.0, 1000.0, 2);
    plane_2->setApperance(*apperance_0);
    plane_2->init();
    
    GLPlane3D* plane_3 = new GLPlane3D(-500.0, 500.0, 1000.0, 1000.0, 1000.0, 1);
    plane_3->setApperance(*apperance_0);
    plane_3->init();
    
    GLPlane3D* plane_4 = new GLPlane3D(-1000.0, 500.0, 750.0, 500.0, 1000.0, 2);
    plane_4->setApperance(*apperance_0);
    plane_4->init();
    
    GLPlane3D* plane_5 = new GLPlane3D(-2000.0, 500.0, 1000.0, 2000.0, 1000.0, 1);
    plane_5->setApperance(*apperance_8);
    plane_5->init();
    
    GLPlane3D* plane_6 = new GLPlane3D(-3000.0, 500.0, 0.0, 2000.0, 1000.0, 2);
    plane_6->setApperance(*apperance_8);
    plane_6->init();
    
    GLPlane3D* plane_25 = new GLPlane3D(-2900.0, 500.0, 0.0, 1500.0, 1000.0, 2);
    plane_25->setApperance(*apperance_1);
    plane_25->init();
    
    GLPlane3D* plane_26 = new GLPlane3D(-1500.0, 500.0, 0.0, 1500.0, 1000.0, 2);
    plane_26->setApperance(*apperance_7);
    plane_26->init();
    
    
    GLPlane3D* plane_7 = new GLPlane3D(-1000.0, 500.0, -750.0, 500.0, 1000.0, 2);
    plane_7->setApperance(*apperance_0);
    plane_7->init();
    
    GLPlane3D* plane_8 = new GLPlane3D(-2000.0, 500.0, -1000.0, 2000.0, 1000.0, 1);
    plane_8->setApperance(*apperance_8);
    plane_8->init();
    
    GLPlane3D* plane_9 = new GLPlane3D(0.0, 500.0, -1000.0, 2000.0, 1000.0, 1);
    plane_9->setApperance(*apperance_0);
    plane_9->init();
    
    GLPlane3D* plane_10 = new GLPlane3D(500.0, 0.0, 1500.0, 1000.0, 1000.0, 3);
    plane_10->setApperance(*apperance_0);
    plane_10->init();
    
    GLPlane3D* plane_11 = new GLPlane3D(0.0, 0.0, 0.0, 2000.0, 2000.0, 3);
    plane_11->setApperance(*apperance_0);
    plane_11->init();
    
    GLPlane3D* plane_12 = new GLPlane3D(-2000.0, 0.0, 0.0, 2000.0, 2000.0, 3);
    plane_12->setApperance(*apperance_8);
    plane_12->init();
    
    GLPlane3D* plane_13 = new GLPlane3D(-1000.0, 500.0, 400.0, 200.0, 1000.0, 2);
    plane_13->setApperance(*apperance_0);
    plane_13->init();
    
    GLPlane3D* plane_14 = new GLPlane3D(-1000.0, 500.0, -400.0, 200.0, 1000.0, 2);
    plane_14->setApperance(*apperance_0);
    plane_14->init();
    
    GLPlane3D* plane_15 = new GLPlane3D(-1000.0, 900.0, 0.0, 600.0, 200.0, 2);
    plane_15->setApperance(*apperance_0);
    plane_15->init();
    
    GLPlane3D* plane_16 = new GLPlane3D(950.0, 650.0, 1100.0, 400.0, 300.0, 2);  //painting
    plane_16->setApperance(*apperance_0);
    plane_16->init();
    
    GLPlane3D* plane_17 = new GLPlane3D(6.0, 650.0, 1300.0, 400.0, 300.0, 2);  //painting
    plane_17->setApperance(*apperance_0);
    plane_17->init();
    
    GLPlane3D* plane_18 = new GLPlane3D(950.0, 650.0, 100.0, 400.0, 300.0, 2);  //painting
    plane_18->setApperance(*apperance_0);
    plane_18->init();
    
    GLPlane3D* plane_19 = new GLPlane3D(-500.0, 250.0, 997.0, 400.0, 300.0, 1);  //painting
    plane_19->setApperance(*apperance_3);
    plane_19->init();
    
    GLPlane3D* plane_20 = new GLPlane3D(-500.0, 650.0, 997.0, 400.0, 300.0, 1);  //painting
    plane_20->setApperance(*apperance_3);
    plane_20->init();
    
    GLPlane3D* plane_21 = new GLPlane3D(-1000.0, 400.0, 0.0, 600.0, 800.0, 2);  //door
    plane_21->setApperance(*apperance_0);
    plane_21->init();
    
    // ceiling
    GLPlane3D* plane_22 = new GLPlane3D(500.0, 1000.0, 1500.0, 1000.0, 1000.0, 3);
    plane_22->setApperance(*apperance_0);
    plane_22->init();
    
    GLPlane3D* plane_23 = new GLPlane3D(0.0, 1000.0, 0.0, 2000.0, 2000.0, 3);
    plane_23->setApperance(*apperance_0);
    plane_23->init();
    
    GLPlane3D* plane_24 = new GLPlane3D(-2000.0, 1000.0, 0.0, 2000.0, 2000.0, 3);
    plane_24->setApperance(*apperance_8);
    plane_24->init();
    
    
    
    //Table creation
    
    GLBox3D* box_1 = new GLBox3D(0.0, 350.0, 0.0, 400, 20, 500, 500, 500);
    box_1->setApperance(*apperance_0);
    box_1->init();
    
    GLBox3D* box_2 = new GLBox3D(-180.0, 170.0, 230.0, 20, 340, 20, 500, 500);
    box_2->setApperance(*apperance_0);
    box_2->init();
    
    GLBox3D* box_3 = new GLBox3D(180.0, 170.0, 230.0, 20, 340, 20, 500, 500);
    box_3->setApperance(*apperance_0);
    box_3->init();
    
    GLBox3D* box_4 = new GLBox3D(-180.0, 170.0, -220.0, 20, 340, 20, 500, 500);
    box_4->setApperance(*apperance_0);
    box_4->init();
    
    GLBox3D* box_5 = new GLBox3D(180.0, 170.0, -220.0, 20, 340, 20, 500, 500);
    box_5->setApperance(*apperance_0);
    box_5->init();
    
    //Chair creation
    
    GLBox3D* box_6 = new GLBox3D(-200.0, 200.0, 0.0, 100, 10, 100, 500, 500);
    box_6->setApperance(*apperance_0);
    box_6->init();
    
    GLBox3D* box_7 = new GLBox3D(-250.0, 290.0, 0.0, 10, 190, 100, 500, 500);
    box_7->setApperance(*apperance_0);
    box_7->init();
    
    GLBox3D* box_8 = new GLBox3D(-245.0, 100.0, 40.0, 10, 200, 10, 500, 500);
    box_8->setApperance(*apperance_0);
    box_8->init();
    
    GLBox3D* box_9 = new GLBox3D(-155.0, 100.0, 40.0, 10, 200, 10, 500, 500);
    box_9->setApperance(*apperance_0);
    box_9->init();
    
    GLBox3D* box_10 = new GLBox3D(-245.0, 100.0, -40.0, 10, 200, 10, 500, 500);
    box_10->setApperance(*apperance_0);
    box_10->init();
    
    GLBox3D* box_11 = new GLBox3D(-155.0, 100.0, -40.0, 10, 200, 10, 500, 500);
    box_11->setApperance(*apperance_0);
    box_11->init();
    
    
    
    // If you want to change appearance parameters after you init the object, call the update function
    apperance_0->updateLightSources();
    apperance_1->updateLightSources();
    
    
    // enable the program
    glUseProgram(apperance_8->getProgram());
    int location = glGetUniformLocation(apperance_8->getProgram(), "texture_delta");
    glUniform1f(location, 0.00f);
    glUniform1f(glGetUniformLocation(apperance_8->getProgram(), "bump_mode"), 0);
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Main render loop
    
    // Set up our green background color
    static const GLfloat clear_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    static const GLfloat clear_depth[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
    // This sets the camera to a new location
    // the first parameter is the eye position, the second the center location, and the third the up vector.
    SetViewAsLookAt(glm::vec3(0.0f, 200.0f, 2400.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    
    
    
    // Enable depth test
    // ignore this line, it allows us to keep the distance value after we proejct each object to a 2d canvas.
    glEnable(GL_DEPTH_TEST);
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Blending
    
    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // sphere->enableNormalVectorRenderer();
    
    glfwSetKeyCallback(window, keyboard_callback);
    
    time(0);
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //// Main render loop
    
      double lastTime = glfwGetTime();
     long nbFrames = 0;
     long vbFrames = 0;
     int choice = 0;
     float rot = 0.0;
     double currentTime;
    
    // This is our render loop. As long as our window remains open (ESC is not pressed), we'll continue to render things.
    while (!glfwWindowShouldClose(window))
    {
        
         currentTime = glfwGetTime();
         //nbFrames++;
         if ( currentTime - lastTime >= 0.2 ){ // If last prinf() was more than 1sec ago
         // printf and reset
         //printf("%f ms/frame\n", 1000.0/double(nbFrames));
         //nbFrames = 0;
         lastTime += 0.2;
           nbFrames++;
         
         
         
         
         }
        
        
        // Clear the entire buffer with our green color (sets the background to be green).
        glClearBufferfv(GL_COLOR, 0, clear_color);
        glClearBufferfv(GL_DEPTH, 0, clear_depth);
        
        
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //// This renders the objects
        
        // Set the trackball locatiom
        SetTrackballLocation(trackball.getRotationMatrix());
        glfwSetKeyCallback(window, keyboard_callback);
        // draw the objects
        
        cs->draw();
        apperance_8->setTexture(texture1);
        apperance_8->finalize();
        
        
        
        
        switch(nbFrames){
         case 0:
         frame0();
         break;
         case 1:
         frame1();
         break;
         case 2:
         frame2();
         break;
         case 3:
         frame3();
         break;
         case 4:
         frame4();
         break;
         case 5:
         frame5();
         break;
         case 6:
         frame6();
         break;
         case 7:
         frame7();
         break;
         case 8:
         frame8();
         break;
         case 9:
         frame9();
         break;
         case 10:
         frame10();
         break;
         case 11:
         frame11();
         break;
         case 12:
         frame12();
         break;
         case 13:
         frame13();
         break;
         case 14:
         frame14();
         break;
         case 15:
         frame15();
         break;
         case 16:
         frame16();
         break;
         case 17:
         frame17();
         break;
         case 18:
         frame18();
         break;
         case 19:
         frame19();
         break;
         case 20:
         frame20();
         break;
         case 21:
         frame21();
         break;
         case 22:
         frame22();
         break;
         case 23:
         frame23();
         break;
         case 24:
         frame24();
         break;
         case 25:
         frame25();
         break;
         case 26:
         frame26();
         break;
         case 27:
         frame27();
         break;
         case 28:
         frame28();
         break;
         case 29:
         frame29();
         break;
         case 30:
         frame30();
         break;
         case 31:
         frame31();
         break;
         case 32:
         frame32();
         break;
         case 33:
         frame33();
         break;
         case 34:
         frame34();
         break;
         case 35:
         frame35();
         break;
         case 36:
         frame36();
         break;
         case 37:
         frame37();
         break;
         case 38:
         frame38();
         break;
         case 39:
         frame39();
         break;
         case 40:
         frame40();
         break;
         case 41:
         frame41();
         break;
         case 42:
         frame42();
         break;
         case 43:
         frame43();
         break;
         case 44:
         frame44();
         break;
         case 45:
         frame45();
         break;
         case 46:
         frame46();
         break;
         case 47:
         frame47();
         break;
         case 48:
         frame48();
         break;
         case 49:
         frame49();
         break;
         case 50:
         frame50();
         break;
         case 51:
         frame51();
         break;
         case 52:
         frame52();
         break;
         case 53:
         frame53();
         break;
         case 54:
         frame54();
         break;
         case 55:
         frame55();
         break;
         case 56:
         frame56();
         break;
         case 57:
         frame57();
         break;
         case 58:
         frame58();
         break;
         case 59:
         frame59();
         break;
         case 60:
         frame60();
         break;
         case 61:
         frame61();
         break;
         case 62:
         frame62();
         break;
         case 63:
         frame63();
         break;
         case 64:
         frame64();
         break;
         case 65:
         frame65();
         break;
         case 66:
         frame66();
         break;
         case 67:
         frame67();
         break;
         case 68:
         frame68();
         break;
         case 69:
         frame69();
         break;
         case 70:
         frame70();
         break;
         case 71:
         frame71();
         break;
         case 72:
         frame72();
         break;
         case 73:
         frame73();
         break;
         case 74:
         frame74();
         break;
         case 75:
         frame75();
         break;
         case 76:
         frame76();
         break;
         case 77:
         frame77();
         break;
         case 78:
         frame78();
         break;
         case 79:
         frame79();
         break;
         case 80:
         frame80();
         break;
         case 81:
         frame81();
         break;
         case 82:
         frame82();
         break;
         case 83:
         frame83();
         break;
         case 84:
         frame84();
         break;
         case 85:
         frame85();
         break;
         case 86:
         frame86();
         break;
         case 87:
         frame87();
         break;
         case 88:
         frame88();
         break;
         case 89:
         frame89();
         break;
         case 90:
         frame90();
         break;
         case 91:
         frame91();
         break;
         case 92:
         frame92();
         break;
         case 93:
         frame93();
         break;
         case 94:
         frame94();
         break;
         case 95:
         frame95();
         break;
         case 96:
         frame96();
         break;
         case 97:
         frame97();
         break;
         case 98:
         frame98();
         break;
         case 99:
         frame99();
         break;
         case 100:
         frame100();
         break;
         case 101:
         frame101();
         break;
         case 102:
         frame102();
         break;
         case 103:
         frame103();
         break;
         case 104:
         frame104();
         break;
         case 105:
         frame105();
         break;
         case 106:
         frame106();
         break;
         case 107:
         frame107();
         break;
         case 108:
         frame108();
         break;
         case 109:
         frame109();
         break;
         case 110:
         frame110();
         break;
         case 111:
         frame111();
         break;
         case 112:
         frame112();
         break;
         case 113:
         frame113();
         break;
         case 114:
         frame114();
         break;
         case 115:
         frame115();
         break;
         case 116:
         frame116();
         break;
         case 117:
         frame117();
         break;
         case 118:
         frame118();
         break;
         case 119:
         frame119();
         break;
         case 120:
         frame120();
         break;
         case 121:
         frame121();
         break;
         case 122:
         frame122();
         break;
         case 123:
         frame123();
         break;
         case 124:
         frame124();
         break;
         case 125:
         frame125();
         break;
         case 126:
         frame126();
         break;
         case 127:
         frame127();
         nbFrames = -1;
         break;
         
         } 
        
        
        
  
      apperance_0->setTexture(texturea2);
        
        box3->setMatrix(model_matrix2);
        box4->setMatrix(model_matrix1);
        box1->setMatrix(model_matrix3);
        box2->setMatrix(model_matrix4);
        box9->setMatrix(model_matrix5);
        box0->setMatrix(model_matrix6);
        box5->setMatrix(model_matrix7);
        box6->setMatrix(model_matrix8);
        box7->setMatrix(model_matrix9);
        box8->setMatrix(model_matrix10);
        
        
        box0->draw();
        box1->draw();
        box2->draw();
        box3->draw();
        box4->draw();
        box5->draw();
        box6->draw();
        box7->draw();
        box8->draw();
        box9->draw();
        
        //loadedModel1->draw();
        plane_21->setMatrix(model_matrixplane);
        
        
        //above this the code should appear
        
        // draw the objects
        cs->draw();
        
         //sphere3->draw();
        
        apperance_6->setTexture(texturea7);
      //  sphere1->setMatrix(model_matrixsphere1);
     // sphere2->setMatrix(model_matrixsphere2);
        sphere3->draw();
        sphere4->draw();
        sphere5->draw();
        sphere1->draw();
        sphere2->draw();
       //apperance_6->setTexture(texture_multi2);
        
        
       //apperance_6->setTexture(texturea5);
       
       
        
       apperance_0->setTexture(texture);
        plane_0->draw();
        plane_1->draw();
        plane_2->draw();
        plane_3->draw();
        plane_9->draw();
        apperance_0->setTexture(texture_disp);
        
        
        plane_22->draw();
        plane_23->draw();
        //plane_24->draw();
        
        
        
     apperance_0->setTexture(texture2);
        plane_21->draw();
        apperance_0->setTexture(texture3);
        plane_13->draw();
        plane_14->draw();
        plane_15->draw();
        //apperance_0->setTexture(texture);
        
        apperance_0->setTexture(texturea4);
        plane_16->draw();
        apperance_0->setTexture(texturea5);
        plane_17->draw();
        apperance_0->setTexture(texture_env);
        plane_18->draw();
        
        apperance_0->setTexture(texturea6);
        //plane_5->draw();
        //plane_6->draw();
        //plane_8->draw();
        
        
        apperance_1->setTexture(texture_multi2);
        plane_25->draw();
        
        
        // apperance_7->setTexture(texture_multi1);
        //plane_26->draw();
        
     
        
        
      //  apperance_3->setTexture(texture_env);
      //  plane_19->draw();
      //  plane_20->draw();
        apperance_0->setTexture(texturea3);
        
        box_1->setMatrix(model_matrixt1);
        box_2->setMatrix(model_matrixt2);
        box_3->setMatrix(model_matrixt3);
        box_4->setMatrix(model_matrixt4);
        box_5->setMatrix(model_matrixt5);
        box_6->setMatrix(model_matrixt6);
        box_7->setMatrix(model_matrixt7);
        box_8->setMatrix(model_matrixt8);
        box_9->setMatrix(model_matrixt9);
        box_10->setMatrix(model_matrixt10);
        box_11->setMatrix(model_matrixt11);
        
        box_1->draw();
        box_2->draw();
        box_3->draw();
        box_4->draw();
        box_5->draw();
        box_6->draw();
        box_7->draw();
        box_8->draw();
        box_9->draw();
        box_10->draw();
        box_11->draw();
        
        apperance_9->setTexture(texture1);
       plane_11->draw();
        plane_12->draw();
        
        apperance_0->setTexture(texture1);
        plane_10->draw();
        
        
        
        apperance_0->setTexture(texture_bump);
        plane_5->draw();
        plane_6->draw();
        plane_8->draw();
        plane_24->draw();
        plane_4->draw();
        plane_7->draw();
        
        /* glUseProgram(apperance_2->getProgram());
         float time = (float)clock() / CLOCKS_PER_SEC;
         float delta = 0.05f * sin(time * 1.0) + 0.05f;
         glUniform1f(location, delta);*/
        
       apperance_9->setTexture(texturea8);
       h1->draw();
        
        // change the texture appearance blend mode
        bool ret = texture->setTextureBlendMode(g_change_texture_blend);
        if (ret)apperance_0->updateTextures();
        
        
        
        
        // Swap the buffers so that what we drew will appear on the screen.
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    
    delete cs;
    
    
}


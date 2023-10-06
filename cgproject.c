#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include<string.h>
#define pi 3.142
static GLfloat angle = 0;
static int flag=0;
static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    glOrtho(-1000, 1000, -1000, 1000,-1,1);
}
void polygon(){
	glColor3f(0.1,0.1,01);
	glBegin(GL_POLYGON);
	glVertex2i(-1000,1000);
	glVertex2i(-1000,-1000);
	glVertex2i(1000,-1000);
	glVertex2i(1000,1000);
	glEnd();
}
void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}

void drawhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawsubhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void drawCircle(float rad, const char* direction) {
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 1.0f, 1.0f);

    for (float i = 0; i < (2 * pi); i += 0.00001) {
        float x, y;
        if (strcmp(direction, "right") == 0) {
            x = rad + 20 * cos(i);
            y = 20 * sin(i);
        } else if (strcmp(direction, "left") == 0) {
            x = -(rad + 20 * cos(i));
            y = 20 * sin(i);
        } else if (strcmp(direction, "top") == 0) {
            x = 20 * cos(i);
            y = rad + 20 * sin(i);
        } else if (strcmp(direction, "down") == 0) {
            x = 20 * cos(i);
            y = -(rad + 20 * sin(i));
        } else if (strcmp(direction, "topleft") == 0) {
            x = -((rad - 175) + 20 * cos(i));
            y = ((rad - 175) + 20 * sin(i));
        } else if (strcmp(direction, "topright") == 0) {
            x = ((rad - 175) + 20 * cos(i));
            y = ((rad - 175) + 20 * sin(i));
        } else if (strcmp(direction, "downleft") == 0) {
            x = -((rad - 175) + 20 * cos(i));
            y = -((rad - 175) + 20 * sin(i));
        } else if (strcmp(direction, "downright") == 0) {
            x = ((rad - 175) + 20 * cos(i));
            y = -((rad - 175) + 20 * sin(i));
        }

        glVertex2f(x, y);
    }

    glEnd();
}

void display()
{	
	
    glClearColor(0.0f, 0.0f, 0.0f, 1);

    if (value == -1)
    {
    
        char cn[] = "ST Joseph Engineering College Vamanjoor";
        drawhead(-450, 900, 0, cn);
        
        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawhead(-550, 650, 0, dn);

        char prn[] = "A Mini Project On";
        drawsubhead(-250, 450, 0, prn);
        char pro[] = "ATOM SIMULATOR";
        drawhead(-350, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-690, -150, 0, pb);

        char p1[] = "Bhavish J B";
        drawhead(-690, -250, 0, p1);
        char p1u[] = "4SO20CS025";
        drawsubhead(-690, -300, 0, p1u);

        char p2[] = "C S Shravan Kumar";
        drawhead(-690, -400, 0, p2);
        char p2u[] = "4SO20CS028";
        drawsubhead(-690, -450, 0, p2u);


        char in[] = "Press enter to Continue";
        drawhead(-250, -700, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(250);
        char n[] = "NUCLEUS";
        drawString(-90, 20, 0, n);
        char s[] = "ℹ️";
        drawString(-325, -60, 0, s);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT FROM MENU";
            drawhead(-490, 900, 0, nu);
        }
    }
    if (value == 1)
    {
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");     // eleright
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
	drawCircle(400,"right");     // eleright
	drawCircle(400,"left");  // eleleft
        char e[] = "ELECTRON";
        drawString(420, 0, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");     // eleright
	drawCircle(400,"left");  // eleleft
	drawCircle(600,"top");     // eletop
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");     // eleright
	drawCircle(400,"left");  // eleleft
	drawCircle(600,"top");     // eletop
	drawCircle(600,"down");  // eledown
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
    	drawCircle(600,"downleft");    // eledl
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
    	drawCircle(600,"topleft");             // eletl
    	drawCircle(600,"downleft");          // eledl
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
    	drawCircle(600,"topleft");             // eletl
    	drawCircle(600,"downleft");          // eledl
    	drawCircle(600,"downright");             // eledr
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
    	drawCircle(600,"topleft");             // eletl
    	drawCircle(600,"downleft");          // eledl
    	drawCircle(600,"downright");             // eledr
    	drawCircle(600,"left");   // eleleft
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        drawCircle(400,"right");      // eleright
        drawCircle(400,"left");   // eleleft
        drawCircle(600,"top");      // eletop
        drawCircle(600,"down");   // eledown
        drawCircle(600,"topright");       // eletr
    	drawCircle(600,"topleft");             // eletl
    	drawCircle(600,"downleft");          // eledl
    	drawCircle(600,"downright");             // eledr
    	drawCircle(600,"left");   // eleleft
    	drawCircle(600,"right");      // eleright
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        
        glPopMatrix();
        glutSwapBuffers();
    }
    
    

    glutSwapBuffers();
}


void description() {
	//glClearColor(1.0f, 0.5f, 0.0f, 1);
	polygon();
	
	glutIdleFunc(NULL);
	glClear(GL_COLOR_BUFFER_BIT);
    char d[4][200];
	drawhead(-800, 920 , 0, "DESCRIPTION :-");
    switch (value) {
    case -1:
        strcpy(d[0], "Please select a element from the menu ");
        for (int j = 0; j < 1; j++) {
            drawsubhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 1:
        strcpy(d[0], "Hydrogen (H):");
        strcpy(d[1], "Behavior: Hydrogen is a highly flammable gas and is the lightest element. It has a low boiling point and can form explosive mixtures with air.");
        strcpy(d[2], "Nature: It is the most abundant element in the universe and plays a crucial role in the formation of stars.");
        strcpy(d[3], "Properties: Hydrogen is odorless, colorless, and tasteless. It is a nonmetal and has three isotopes: protium, deuterium, and tritium.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        
        glutIdleFunc(NULL);
        break;

    case 2:
        strcpy(d[0], "Helium:");
        strcpy(d[1], "Behavior: Helium is a noble gas and is the second lightest element. It is chemically inert and has low solubility in water.");
        strcpy(d[2], "Nature: It is the second most abundant element in the universe, primarily formed during the process of nuclear fusion in stars.");
        strcpy(d[3], "Properties: Helium is colorless, odorless, and non-toxic. It has a low boiling point and is commonly used in balloons and as a coolant.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 3:
        strcpy(d[0], "Lithium:");
        strcpy(d[1], "Behavior: Lithium is a highly reactive metal and is the lightest solid element. It reacts vigorously with water and forms strong compounds.");
        strcpy(d[2], "Nature: It is a relatively rare element and is found in small amounts in rocks, minerals, and saltwater.");
        strcpy(d[3], "Properties: Lithium is silvery-white in color and has low density. It is used in batteries, alloys, and pharmaceutical applications.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        glutSwapBuffers();
        break;

    case 4:
        strcpy(d[0], "Beryllium:");
        strcpy(d[1], "Behavior: Beryllium is a hard, brittle metal and is toxic in its pure form. It has excellent thermal conductivity and resists oxidation.");
        strcpy(d[2], "Nature: It is a relatively rare element and is found in minerals like beryl and bertrandite.");
        strcpy(d[3], "Properties: Beryllium is lightweight, corrosion-resistant, and has high tensile strength. It is used in aerospace, nuclear, and medical industries.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 5:
        strcpy(d[0], "Boron:");
        strcpy(d[1], "Behavior: Boron is a metalloid and is a poor conductor of electricity. It forms strong covalent bonds and behaves as a nonmetal.");
        strcpy(d[2], "Nature: It is found in various compounds in minerals and rocks. Boron compounds are used in a variety of industrial applications.");
        strcpy(d[3], "Properties: Boron has a low density and high melting point. It is used in the production of glass, ceramics, and as a dopant in semiconductors.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 6:
        strcpy(d[0], "Carbon:");
        strcpy(d[1], "Behavior: Carbon is a versatile element and forms the basis of all organic compounds. It can exist in various allotropes, including diamond and graphite.");
        strcpy(d[2], "Nature: It is the fourth most abundant element in the universe and is a building block of life.");
        strcpy(d[3], "Properties: Carbon has a high melting point, is a good conductor of electricity in its graphite form, and is used in numerous industries.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 7:
        strcpy(d[0], "Nitrogen:");
        strcpy(d[1], "Behavior: Nitrogen is a colorless, odorless gas and is relatively inert. It is a vital component of biological molecules, including proteins and nucleic acids.");
        strcpy(d[2], "Nature: It is the most abundant element in Earth's atmosphere and plays a crucial role in the nitrogen cycle.");
        strcpy(d[3], "Properties: Nitrogen is nonmetallic, diatomic, and has a low boiling point. It is used in various industrial processes and as a cryogenic agent.");
        for (int j = 0; j < 4; j++) {
          drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 8:
        strcpy(d[0], "Oxygen:");
        strcpy(d[1], "Behavior: Oxygen is a highly reactive gas and supports combustion. It is essential for respiration and plays a vital role in many biological processes.");
        strcpy(d[2], "Nature: It is the most abundant element in the Earth's crust and is a major component of the atmosphere.");
        strcpy(d[3], "Properties: Oxygen is a colorless, odorless gas and is a strong oxidizing agent. It is used in various industrial applications, including steelmaking.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 9:
        strcpy(d[0], "Fluorine:");
        strcpy(d[1], "Behavior: Fluorine is a highly reactive, corrosive gas and is the most electronegative element. It readily forms compounds with other elements.");
        strcpy(d[2], "Nature: It is the lightest halogen and is found in minerals, rocks, and as fluoride ions in water.");
        strcpy(d[3], "Properties: Fluorine is pale yellow in color and is used in the production of fluoropolymers, refrigerants, and toothpaste.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 10:
        strcpy(d[0], "Neon:");
        strcpy(d[1], "Behavior: Neon is a noble gas and is chemically inert. It emits a distinctive orange-red glow when electrically excited.");
        strcpy(d[2], "Nature: It is a rare gas and is found in trace amounts in the Earth's atmosphere.");
        strcpy(d[3], "Properties: Neon is colorless, odorless, and has low solubility in water. It is commonly used in neon signs and as a coolant in cryogenics.");
        for (int j = 0; j < 4; j++) {
            drawhead(-800, 860 - (100 * j), 0, d[j]);
        }
        glutIdleFunc(NULL);
        break;

    case 0:
    glutIdleFunc(NULL);
        break;
    }
    glutSwapBuffers();
    glutPostRedisplay();
    
}

void rotate()
{
    angle = angle + 1.0;
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) glutIdleFunc(NULL);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) glutIdleFunc(rotate);
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 27)
    {
        glutReshapeWindow(750, 750);
    }
     else if(key == 'd' || key=='D'){
     	//glutIdleFunc(NULL);
     	//flag=1;
    	//description();
    	glutDisplayFunc(description);	
    }
    else if(key == 'e' ||  key=='E'){
    	glutDisplayFunc(display);
    	glutIdleFunc(rotate);
    }
    
}

void menu(int option)
{	glutIdleFunc(NULL);
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
   
    else if(option==14){
        value=-1;
    }
    else if(option==15){
	glutDisplayFunc(description);
    }
    else if(option==16){
    	glutDisplayFunc(display);
    	glutIdleFunc(rotate);
    }
    else
    {
        value = option;
    }
    if(option!=12){
    	glutIdleFunc(rotate);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}
void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}
void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START", 11);
    glutAddMenuEntry("STOP", 12);
    glutAddMenuEntry("DESCRIPTION",15);
    glutAddMenuEntry("EXIT DESCRIPTION",16);
    glutAddMenuEntry("HOME",14);
    glutAddMenuEntry("EXIT", 13);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(750, 750);
    glutCreateWindow("ATOM SIMULATOR");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    createMenu();
    glutMainLoop();
    return 0;
}

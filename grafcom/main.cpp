// E1E121050 - ANNISA AZ'ZAHRA TARIMANA
// LINE 1 SAMPAI LINE 55

#include <windows.h> //membersihkan layar
#include <GL/glut.h> //library grafik

    //buat 3 buah method
    void cylinder(float rbase,float rtop,float height); //menggambar silinder
    void blok(float tebal,int ratiol,int ratiop); //menggambar blok
    void bilah (float r_inner,float r_outer,float tebal,int batang); //menggambar bilah

    //atur layar
    int screen_width=500;// berfungsi untuk mengatur lebar screen
    int screen_height=600;//berfungsi untuk mengatur tinggi screen
    int button_up=0,button_down=0 ;//berfungsi mengatur tombol ke atas dan ke bawah
    int Turn=0; //berfungsi untuk mengatur arah pada layar

    //atur variabel awal untuk pergerakan
    double rotation_y=0,rotation_y_plus=-10,direction;// mengatur rotasi agar searah jarum jam
    double Rhead=0,Rheadplus=0; //mengatur arah putaran kipas agar tetap stabil 180* kedepan
    double rotate_All=0,All_plus=0; //rotate all untuk mengatur posisi hadap kipas & all plus untuk mengatur kecepatan putar kipas
    double Angguk=0,Anggukplus=0; //mengatur naik turunnya kipas
    double press=0,pressplus,pressplus1=0,pressplus2=0,pressplus3=0,pressplus4=0,pressplus5=0; //tombol pada kipas

    bool Toleh=false,Tolehpress=false; //kipas angin bergerak
    bool RightTurn=true; //kipas angin bergerak ke kanan
    bool speed1=false,speed2=false,speed3=false,speed4=false,speed5=false; //kecepatan awal kipasdi speed1

    //seting pencahayaan 4 parameter
    //GLfloat ambient_light[]={0.3,0.3,0.45,1.0};
    GLfloat ambient_light[]={0.0,0.0,0.45,1.0};//GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3
    //GLfloat  source_light[]={0.9,0.8,0.8,1.0};
    GLfloat  source_light[]={0.8,0.8,0.8,1.0};
    //GLfloat     light_pos[]={7.0,0.0,1.0,1.0};
    GLfloat     light_pos[]={5.0,0.0,6.0,1.0};

    void init(void) //fungsi untuk membuat tempat menggambar
    {

    glShadeModel(GL_SMOOTH);// MENGHALUSKAN TEKSTUR
    //glViewport(1000,0,screen_width,screen_height);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f);

    glEnable (GL_DEPTH_TEST); //pencahayaan
    //glPolygonMode   (GL_FRONT_AND_BACK,GL_FILL); //menggunakan mode polygon
    glEnable (GL_LIGHTING); // pemanggilan parameter lihghting
    glLightModelfv  (GL_LIGHT_MODEL_AMBIENT,ambient_light); //menyetel model paramater pencahayaan menggunakan mode ambient (4 parameter)
    glLightfv (GL_LIGHT0,GL_DIFFUSE,source_light); //menetapkan nilai parameter sumber cahaya individual.
    glLightfv (GL_LIGHT0,GL_POSITION,light_pos); //
    glEnable (GL_LIGHT0); //mengaktifkan nilai sumber cahaya
    glEnable (GL_COLOR_MATERIAL); //Menentukan parameter material mana yang melacak warna saat ini.
    glColorMaterial (GL_FRONT,GL_AMBIENT_AND_DIFFUSE);//Nilai yang diterima adalah
    }

//E1E121074 - MUHAMMAD AZRIEL SAKTIAWAN
// LINE 61 SAMPAI 109
//membuat method risize agar saat layar di maxzimize gambar mengikuti layar sehingga tidak merubah ukuran dari kipasnya
    void resize(int width,int height) //membuat fungsi dengan nama mengubah lebar dan panjangnya
    {
    screen_width=width; //untuk lebar layar
    screen_height=height; //untuk panjang layar

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //fungsinya untuk mendeskripsikan warna tampilan windows yang dibuat
    glViewport(0,0,screen_width,screen_height); //untuk menampilkan objek tepat ditengah layar
    glMatrixMode(GL_PROJECTION); //Untuk mengindikasikan tekstur matrix yang digunakan sebelum memproses perintah transformasi
    glLoadIdentity(); //Untuk membersihkan modifiabel matrix yang ada saat ini, untuk kebutuhan penggunaan selanjutnya
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f); //untuk mengubah besar dan kecil ukuran objek tersebut

    glutPostRedisplay(); //yang berfungsi mengirimkan perintah untuk mengaktifkan display secara berkala.
    }

    //buat method buat method display(method penampilan gambar
    void display(void) //membuat fungsi dengan display atau tampilan
    {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //fungsinya untuk mendeskripsikan warna tampilan windows yang dibuat
    glMatrixMode(GL_MODELVIEW); ////Untuk mengindikasikan tekstur matrix yang digunakan sebelum memproses perintah transformasi
    glLoadIdentity(); //Untuk membersihkan modifiabel matrix yang ada saat ini, untuk kebutuhan penggunaan selanjutnya

    glTranslatef(0.0,-15,-70); //untuk menghasilkan terjemahan dari matrix yang ditentukan 3 parameter(x,y,z)
    glPushMatrix(); //untuk menyimpan koordinat yang ada
    glRotatef(270,1.0,0.0,0.0); //bentuk transformasi yang digunakan untuk memutar posisi suatu benda
    rotate_All+=All_plus; //berfungsi untuk memutar seluruh objek kipas
    glRotatef(rotate_All,0.0,0.0,1.0);
    cylinder(2.5,1.5,16); // cilinder btang bawah2
    cylinder(2.5,2.5,6); // cilinder batang bawah1
   glPushMatrix(); //untuk menyimpan koordinat yang ada
   glTranslatef(0.0,0.0,14);
    glRotatef(90,0.0,1.0,0.0);
    Angguk+=Anggukplus; // untuk naik turunnya kipas page up page down
    glRotatef(Angguk,0.0,0.0,1.0); //bentuk transformasi yang digunakan untuk mennaik turunkan posisi suatu benda
        Anggukplus=0;
     glPushMatrix(); //untuk menyimpan koordinat dari angguk
     glRotatef(270,0.0,1.0,0.0);
     glTranslatef(0.0,0.0,1);
     cylinder(0.5,1,4);// cilinder batang atas
     glPopMatrix(); //untuk memanggil suatu fungsi yang telah disimpan pada glpushmatrix
    glutSolidTorus(1.5,2,6,16); //
    glTranslatef(0.0,0.0,-2);
    cylinder(1,1,4.3);//silinder penghubung batang atas dan batang bawah
    glTranslatef(0.0,0.0,2);
    glRotatef(270,0.0,1.0,0.0);
         glPushMatrix(); //untuk menyimpan koordinat yang ada
         glTranslatef(0.0,0.0,10);
         glRotatef(90,1.0,0.0,0.0);
     //turn left-right for fan head  10/9/2003




//lukman awal
//E1E121004 LA ODE LUKMANA
    // definisikan kondisi pergerakan penolehan
     if ( Toleh==true)
     {
     if(Turn >= 60)      // max degrees right
        RightTurn =false;
     if(Turn <=-60)  // max degrees left
        RightTurn =true;
     if(RightTurn == true )
     {
     Rheadplus++;
     Turn++;
     }
     else
     {
     Rheadplus--;
     Turn--;
     }
     }
     Rhead=Rhead+Rheadplus;
     glRotatef(Rhead,0.0,1.0,0.0);
     Rheadplus=0;
     // end turn left-right for fan head

     glTranslatef(0.0,0.0,-3.0);
     cylinder(4,4,6);// silinder belakang kipas
     cylinder(1,0.5,15);//silinder tonjolan di depan kipas
     glRotatef(270,1.0,0.0,0.0);
     if(Tolehpress==true)  // press down turn left-right head button
     cylinder(0.3,0.5,6);
     else // pull up turn left-right head button
     cylinder(0.3,0.5,7);
     glRotatef(90,1.0,0.0,0.0);
         glPushMatrix();
       glTranslatef(0.0,0.0,11);
       glutWireTorus(5,7,10,64);
       glutSolidTorus(0.5,12,10,64);
       rotation_y+=rotation_y_plus;
       if(rotation_y>359)rotation_y=0;
       glRotatef(rotation_y,0.0,0.0,1.0);
       bilah(3,10,3,5); // bilah(inner radius, outer radius, thickness, qty bilah)
         glPopMatrix();
       glPopMatrix();
     glPopMatrix();
     glRotatef(90,1.0,0.0,0.0);
     glTranslatef(0.0,-1.0,-4);
     blok(2,7,10);// blok bawah(papan kontrol)


//lukman akhir



//E1E120096 WA ODE NAILA NTANGU
//LINE 167-222

     // speed selection   11/9/2003
     glTranslatef(-6,1,14);
     glRotatef(270,1.0,0.0,0.0);
     glTranslatef(2.0,0.0,0.0);
     glPushMatrix();
     glRotatef(pressplus5,1.0,0.0,0.0);
     blok(0.5,2,2); // untuk blok tombol off
     glPopMatrix();
     glTranslatef(2.0,0.0,0.0);
     glPushMatrix();
     glRotatef(pressplus1,1.0,0.0,0.0);
     blok(0.5,2,2);// untuk blok tombil f1
     glPopMatrix();
     glTranslatef(2.0,0.0,0.0);
     glPushMatrix();
     glRotatef(pressplus2,1.0,0.0,0.0);
     blok(0.5,2,2);//untuk blok tombol f2
     glPopMatrix();
     glTranslatef(2.0,0.0,0.0);
glPushMatrix();
     glRotatef(pressplus3,1.0,0.0,0.0);
     blok(0.5,2,2);// untuk blok tombol f3
     glPopMatrix();
     glTranslatef(2.0,0.0,0.0);
     glPushMatrix();
     glRotatef(pressplus4,1.0,0.0,0.0);
     blok(0.5,2,2);//untuk blok tombolf4
     glPopMatrix();
     pressplus5=0;
     //end of speed selection
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
    }


    void cylinder(float rbase,float rtop,float height)
    {
    float i;
    glPushMatrix();
    glTranslatef(0.0,0.0,-rbase/4);
    glutSolidCone(rbase,0,32,4);//membuat objek kerucut
    for(i=0;i<=height;i+=rbase/8)
    {
    glTranslatef(0.0,0.0,rbase/8);
    glutSolidTorus(rbase/4,rbase-((i*(rbase-rtop))/height),16,16); //donat
    }
    glTranslatef(0.0,0.0,rbase/4);
    glutSolidCone(rtop,0,32,4);
    glPopMatrix();
    }

//line akhir naila


//E1E120052_UMRIATI
//line 225-294
void bilah (float r_inner,float r_outer,float tebal,int batang)
    {
    float i;
    glPushMatrix();
    glTranslatef(0.0,0.0,-tebal/4);
    cylinder(r_inner,r_inner,tebal);
    glTranslatef(0.0,0.0,tebal/2);
    glRotatef(90,0.0,1.0,0.0);
    for(i=0;i<batang;i++)
        {
        glTranslatef(0.0,0.0,r_inner);
        glRotatef(315,0.0,0.0,1.0);
        blok(0.5,r_inner*4.5,(r_outer-r_inner+(r_inner/4))*2);
        glRotatef(45,0.0,0.0,1.0);
        glTranslatef(0.0,0.0,-r_inner);
        glRotatef(360/batang,1.0,0.0,0.0);
        }
    glPopMatrix();
    }


    void blok(float tebal,int ratiol,int ratiop)
    {
    float i,j;
    glPushMatrix();
        for(i=0;i<ratiop;i++)
        {
        glTranslatef(-(ratiol+1)*tebal/2,0.0,0.0);
        for(j=0;j<ratiol;j++)
            {
            glTranslatef(tebal,0.0,0.0);
            glutSolidCube(tebal); // membuat kubus
            }
        glTranslatef(-(ratiol-1)*tebal/2,0.0,tebal);
        }
    glPopMatrix();
    }

    //efek keyboard
    void keyboard_s(int key,int x,int y)
    {
        if (rotation_y_plus !=0) //jika rotasi y tdk=0
        direction=(rotation_y_plus/abs(rotation_y_plus)); //arah=rotasi y/absolut rotasi y
        else
        direction=-1;
        switch(key) //periksa var key
        {
        case GLUT_KEY_UP:// menaikan kipas
            rotation_y_plus++; //jalankan glut key up jika var key nya == GLUT_KEY_UP
            break; //break ini supaya langsung distop kalo kondisi terpenuhi
        case GLUT_KEY_DOWN:// menurunkan kipas
            rotation_y_plus--;
            break;
        case GLUT_KEY_END:// stop kipas
            rotation_y_plus=0;
            speed1=false;
            pressplus1=0;
            speed2=false;
            pressplus2=0;
            speed3=false;
            pressplus3=0;
            speed4=false;
            pressplus4=0;
            pressplus5=180;
            Toleh=false;
            break;

    // Line akhir umriati


    //E1E121010-NURUL AZIZAH
    //LINE 297-394
    case GLUT_KEY_F1://speed ke-1
        if(speed1 == false)//pengkondisian awal, jika speed1 false maka kerjakan
        {
        rotation_y_plus=20*direction;//tampilan kecepatan perputaran baling2
        speed1=true;//jalankan
        pressplus1=180;//tombol kipas f1 turun
        speed2=false; //kondisi false
        pressplus2=0; // tobol kipas f2 naik
        speed3=false;//kondisi false
        pressplus3=0;//tombol kipas f3 naik
        speed4=false;//kondisi false
        pressplus4=0;//tombol kipas f4 naik
        if(Tolehpress == true)//lakukan perputaran kipas
        Toleh=true; //dikerjakan
        }
        else //pengkondisian selanjutnya
        {
        speed1=false;//jika kondisi awal masih false maka
        pressplus1=0;//tombol kipas naik
        rotation_y_plus=0;//pemutaran baling berhenti
        Toleh=false;//perputaran kipas berhenti
        }
        break;//kondisi telah dipenuhi hentikan pengeksekusian
    case GLUT_KEY_F2://speed ke-2
        if(speed2 == false)//pengkondisian awal, jika speed2 false maka peed2 false maka kerjakan
        {
        rotation_y_plus=30*direction;//tampilan kecepatan perputaran baling2
        speed1=false;//kondisi false
        pressplus1=0;//tombol kipas f1 naik
        speed2=true; //jalankan
        pressplus2=180; // tombol kipas f2 turun
        speed3=false;//kondisi false
        pressplus3=0;//tombol kipas f3 naik
        speed4=false;//kondisi false
        pressplus4=0;//tombol kipas f4 naik
        if(Tolehpress == true)//lakukan perputaran kipas
        Toleh=true; //dikerjakan
        }
        else //pengkondisian selanjutnya
        {
        speed2=false;//jika kondisi awal masih false maka
        pressplus2=0;//tombol kipas naik
        rotation_y_plus=0;//pemutaran baling berhenti
        Toleh=false;//perputaran kipas berhenti
        }
        break;//kondisi telah dipenuhi hentikan pengeksekusian
    case GLUT_KEY_F3://speed ke-3
        if(speed3 == false)//pengkondisian awal, jika speed3 false maka kerjakan
        {
        rotation_y_plus=45*direction;//tampilan kecepatan perputaran baling2
        speed1=false;//kondisi false
        pressplus1=0;//tombol kipas f1 naik
        speed2=false; //kondisi false
        pressplus2=0; // tobol kipas f2 naik
        speed3=true;//jalankan
        pressplus3=180;//tombol kipas f3 turun
        speed4=false;//kondisi false
        pressplus4=0;//tombol kipas f4 naik
        if(Tolehpress == true)//lakukan perputaran kipas
        Toleh=true; //dikerjakan
        }
        else //pengkondisian selanjutnya
        {
        speed3=false;//jika kondisi awal masih false maka
        pressplus3=0;//tombol kipas naik
        rotation_y_plus=0;//pemutaran baling berhenti
        Toleh=false;//perputaran kipas berhenti
        }
        break;//kondisi telah dipenuhi hentikan pengeksekusian
    case GLUT_KEY_F4://speed ke-4
        if(speed4 == false)//pengkondisian awal, jika speed4 false maka kerjakan
        {
        rotation_y_plus=60*direction;//tampilan kecepatan perputaran baling2
        speed1=false;//kondisi false
        pressplus1=0;//tombol kipas f1 naik
        speed2=false; //kondisi false
        pressplus2=0; // tobol kipas f2 naik
        speed3=false;//kondisi false
        pressplus3=0;//tombol kipas f3 naik
        speed4=true;//jalankan
        pressplus4=180;//tombol kipas f4 turun
        if(Tolehpress == true)//lakukan perputaran kipas
        Toleh=true; //dikerjakan
        }
        else //pengkondisian selanjutnya
        {
        speed4=false;//jika kondisi awal masih false maka
        pressplus4=0;//tombol kipas naik
        rotation_y_plus=0;//pemutaran baling berhenti
        Toleh=false;//perputaran kipas berhenti
        }
        break;//kondisi telah dipenuhi hentikan pengeksekusian
//Akhir Nurul


//E1E121026_FILDZAH KHALISHAH GHASSANI
//LINE 399 - 453

case GLUT_KEY_F5: //menghentikan pergerakan menoleh kiri dan kanan
if(Tolehpress == false)
{
if(speed1==true||speed2==true||speed3==true||speed4==true)
Toleh=true;
Tolehpress=true;
}
else
{
if(speed1==true||speed2==true||speed3==true||speed4==true)
Toleh=false;
Tolehpress=false;
}
break;
case GLUT_KEY_RIGHT://mengatur tolehan kipas ke kanan secara bertahap
Rheadplus++;
Turn++;
break;
case GLUT_KEY_LEFT://mengatur tolehan kipas ke kiri secara bertahap
Rheadplus--;
Turn--;
break;
case GLUT_KEY_PAGE_UP:// mengatur kipas ke posisi atas
Anggukplus--;
break;
case GLUT_KEY_PAGE_DOWN: // mengatur kipas ke posisi bawah
Anggukplus++;
break;
}
}

// interaksi melalui mouse
    void Mouse_s(int button, int state, int x, int y)
    {
        if (state==0 && button==0)
        All_plus--;
        if (state==0 && button==2)
        All_plus++;
    }

    //pengaturan jendela layar dan pemanggilan fungsi
 int main(int argc,char **argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
        glutInitWindowSize(screen_width,screen_height);
        glutInitWindowPosition(0,0);
        glutCreateWindow("KELOMPOK 4 GENAP");
        glutDisplayFunc(display);
        glutIdleFunc(display);
        glutReshapeFunc(resize);
        glutSpecialFunc(keyboard_s);
        glutMouseFunc(Mouse_s);
        init();
        glutMainLoop();
        return(0);
    }


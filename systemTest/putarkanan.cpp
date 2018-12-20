
#ifndef PUTARKANAN_CPP
#define PUTARKANAN_CPP

#include "/home/pi/systemTest/library/allLibtune.h"
//#include "/home/pi/Multithreading/Geraklangkah.cpp"
#include "/home/pi/systemTest/library/movement/moveArray.h"
#include "/home/pi/systemTest/library/dynamixel/syncWrite.cpp"

double f2;
double a=0.2;
struct {
	int condition,x_head,y_head;
}data_image;
void verse (){
data_image.x_head=512;
data_image.y_head=512;
}
void putarkanan(){
	
	double x,y,z,sudutX,sudutY,sudutZ,x2,y2,z2,sudutX2,sudutY2,sudutZ2,sudutNgurang;	
	int speed, com7, com8;
	// MIRING //
	x=-13.4; 
	y=0;// miring kaki
        z=0.5;// langkah kaki 

        sudutX=0;//miring badan
        sudutY=15.5;//kebungkukan badan 
        sudutZ=0;//putaran badan

        x2=-13.4; //tinggi kaki kiri
        y2=0;//3;
        z2=0;

        sudutX2=0;
        sudutY2=15.5; 
        sudutZ2=0;

//        dxl_write_word(3,30,300);
  //      dxl_write_word(4,30,724);
        // inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,50,'2');
         inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,100,512,512,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);
        cout<<"Masukkan Speed: ";
        //cin>>speed;
        sleep(2);//5


	f2=0;
	while(f2<=90.0)
   {
	f2=f2+0.1;
	sudutNgurang=f2;
        x=-13.4;//-2*sin(sudutNgurang*3.14/180)*2;
        y=2*sin(sudutNgurang*3.14/180);//1.5 miring kiri
        z=0.5;
        sudutX=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY=15.5;//+sin(sudutNgurang*3.14/180);
        sudutZ=0;//3*(pow(sin(sudutNgurang*3.14/180),2));
	x2=-13.4;//+sin(sudutNgurang*3.14/180)*2;	kiri
      	y2=2*sin(sudutNgurang*3.14/180);//1.5 miring kiri
      	z2=0;
        sudutX2=-2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
        sudutY2=15.5;//-sin(sudutNgurang*3.14/180);
        sudutZ2=0;//-3*(pow(sin(sudutNgurang*3.14/180),2));
	speed=200;//cos(sudutNgurang*3.14/360);//50
	inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,512,512,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);

   }
	f2=0;
	usleep(1000);
// ------------------  ANKAT KAKI DAN MENDARAT //
	while(f2<=180)
	{
		f2=f2+0.08;
		sudutNgurang=f2;
		x=-13.4+2*sin(sudutNgurang*3.14/180);
        	y=1;//-0*sin(sudutNgurang*3.14/180);//cos(sudutNgurang*3.14/360);//2.4
	        z=0.5;//0+0.8-0.8*cos(sudutNgurang*3.14/180);
		sudutX=-3+10*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/	
		sudutY=15.5;//+6*sin(sudutNgurang*3.14/360);
	        sudutZ=512;//+20*sin(sudutNgurang*3.14/360);//1*sin(sudutNgurang*3.14/180)*1.4;;//3*(pow(sin(sudutNgurang*3.14/180),2));
	        x2=-13.4;//+2*sin(sudutNgurang*3.14/180);
	      	y2=1-0*sin(sudutNgurang*3.14/180);// + pidy;//sin(sudutNgurang*3.14/180);//2.4
	      	z2=0;//-0.8+0.8*cos(sudutNgurang*3.14/180);
	        sudutX2=-3+20*sin(sudutNgurang*3.14/180);// - pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/
	        sudutY2=15.5;//-4*sin(sudutNgurang*3.14/360);
		sudutZ2=512-40*sin(sudutNgurang*3.14/360);//-3*(pow(sin(sudutNgurang*3.14/180),2));
		speed=200;//+50*cos(sudutNgurang*3.14/360);	//50
		inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);

	}

	f2=0;
	usleep(5000);
// --------------------------- BALIKIN MIRING //
	while(f2<=90)
	{
		f2=f2+a;
		sudutNgurang=f2;
	        x=-13.4;//-sin(sudutNgurang*3.14/180)*2;
	        y=1-1*sin(sudutNgurang*3.14/180);//2.4
	        z=0.5;//1.6;
	        sudutX=-2+2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
	        sudutY=15.5;//-6*sin(sudutNgurang*3.14/180);
	        sudutZ=512;//-2;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
	        x2=-13.4;//+sin(sudutNgurang*3.14/180)*2;
	        y2=1-1*sin(sudutNgurang*3.14/180);//2.4
	        z2=0;//-1.6;//0.2;//.2;
	        sudutX2=-2+2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
	        sudutY2=15.5;//+4*sin(sudutNgurang*3.14/180);
	        sudutZ2=472;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2 
		speed=200;//cos(sudutNgurang*3.14/360);
		inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);

	}
	f2=0;
	
	usleep(600000);

// ----------------------------- MIRING //	
		while(f2<=90)
		{
			f2=f2+a;
			sudutNgurang=f2;
			x=-13.4;//+sin(sudutNgurang*3.14/180)*2;
			y=-1.5*sin(sudutNgurang*3.14/180);//-1
			z=0.5;//0.5;//cos(sudutNgurang*3.14/180);
			sudutX=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
			sudutY=15.5;//+1*sin(sudutNgurang*3.14/180);
			sudutZ=512;//2;//3*(pow(sin(sudutNgurang*3.14/180),2));
			x2=-13.4;//-sin(sudutNgurang*3.14/180)*2.4;
			y2=-1.5*sin(sudutNgurang*3.14/180);//2
			z2=0;//0.2;//cos(sudutNgurang*3.14/180);
			sudutX2=2*sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
			sudutY2=15.5;//+1*sin(sudutNgurang*3.14/180);
			sudutZ2=472;//-2;//-3*(pow(sin(sudutNgurang*3.14/180),2));
			speed=200;//cos(sudutNgurang*3.14/360);
			inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);

		}
		usleep(5000);
// ------------------------ ANGKAT KAKI DAN MENDARAT/
		f2=0;
		
		while(f2<=180){
			f2=f2+a;
			sudutNgurang=f2;
			x=-13.4+0*sin(sudutNgurang*3.14/180);
			y=-1;//+3*sin(sudutNgurang*3.14/180);//- pidy;//2.4
			z=0.5;//0.4-0.4*cos(sudutNgurang*3.14/180);
			sudutX=2+10*sin(sudutNgurang*3.14/180);//- pidx;/*(pow(sin(sudutNgurang*3.14/180),2));*/
			sudutY=15.5;//-4*sin(sudutNgurang*3.14/360);//+sin(sudutNgurang*3.14/180);
			//speed=200*cos(sudutNgurang*3.14*0.5/180);
			sudutZ=512;//-20*sin(sudutNgurang*3.14/360);//3*(pow(sin(sudutNgurang*3.14/180),2));
			x2=-13.4+8*sin(sudutNgurang*3.14/180);
			y2=-1+0*sin(sudutNgurang*3.14/180);//2.4
			z2=0;//0.4-0.4*cos(sudutNgurang*3.14/180);
			sudutX2=2+30*sin(sudutNgurang*3.14/180);//sin(sudutNgurang*3.14/180);/*(pow(sin(sudutNgurang*3.14/180),2));*/
			sudutY2=15.5;//+2*sin(sudutNgurang*3.14/360);
			sudutZ2=472+40*sin(sudutNgurang*3.14/360);//472+40//-3*(pow(sin(sudutNgurang*3.14/180),2));
			speed=200;//+50*sin(sudutNgurang*3.14/180);
			inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);

		}
		f2=0;
		usleep(5000);
		// BALIKIN MIRING//
		
		while(f2<=90){
			f2=f2+a;
			sudutNgurang=f2;
			x=-13.4;//+sin(sudutNgurang*3.14/180)*1.4;
			y=-1+1*sin(sudutNgurang*3.14/180);//2.4
			z=0.5;//cos(sudutNgurang*3.14/180);
			sudutX=2-2*sin(sudutNgurang*3.14/180);
			sudutY=15.5;//-4+4*sin(sudutNgurang*3.14/180);
			sudutZ=512;//3*(pow(sin(sudutNgurang*3.14/180),2));
			x2=-13.4;//-sin(sudutNgurang*3.14/180)*1.4;
			y2=-1+1*sin(sudutNgurang*3.14/180);//2.4
			z2=0;//cos(sudutNgurang*3.14/180);
			sudutX2=2-2*sin(sudutNgurang*3.14/180);
			sudutY2=15.5;//+2*sin(sudutNgurang*3.14/180);
			sudutZ2=512;//-3*(pow(sin(sudutNgurang*3.14/180),2));
			speed=200;//cos(sudutNgurang*3.14/360);
			//inverseAndre(sudutX,sudutY,sudutZ,x,y,z,sudutX2,sudutY2,sudutZ2,x2,y2,z2,speed,'2');
			inverseAndre(sudutX,sudutY,0,x,y,z,sudutX2,sudutY2,0,x2,y2,z2,speed,sudutZ,sudutZ2,'2',500,500,250,780,500,500,data_image.x_head,data_image.y_head);
}
		
		f2=0;
		usleep(5000);
		
	//	int id[] = {20};
	//	int data1[][18] = {512};
	//	int delay1[] = {1000};
	//	int speed1[] = {100};
//		kirimPacketGerak(1, 1, 1, id, data1, 1, delay1, speed1);
		
}

int main(){

if(dxl_initialize(0,1)==0){
        cout<<"Error connecting"<<endl;
        return 0;
    }

else{
                cout<<"connect success!"<<endl;
        }

data_image.x_head=512;
data_image.y_head=512;
while(1){

        putarkanan();
	usleep(3000);
}
return 0;
        }



#endif

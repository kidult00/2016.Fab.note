import processing.serial.*;
Serial myPort;
int lf = 10;
 
void setup(){
  size(300,300);
  myPort = new Serial(this,"/dev/tty.usbserial-A400gwhT",9600);
  textAlign(CENTER, CENTER);
  fill(255);
  textSize(20);
}
 
void draw(){
  while(myPort.available() > 0){
    String str = myPort.readStringUntil(lf);

    if(str!=null){
      int value = Integer.parseInt(trim(str));
 
       if (value >900) {
        print("it's dark ");
        println(value);
        background(0,0,0);
        text("it's dark! ",150,150);
       } 
       else{
        print("it's getting light ");
        println(value);
        background(100,100,150);
        text("it's getting light ",150,150);
       }
    }
  }
}
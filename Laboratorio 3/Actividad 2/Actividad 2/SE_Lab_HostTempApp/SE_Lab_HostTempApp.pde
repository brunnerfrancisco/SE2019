
/**
 * Ejemplo de skecth Processing para el desarrollo del Laboratorio.
 *
 * Este skecth implementa un programa en el host que tiene la capacidad de
 * graficar funciones que evolucionan en el tiempo y además permite la
 * presentación de datos simples mediante Labels, y la captura de eventos
 * del usuario mediante la implementación de botones simples.
 *
 * La aplicación divide la ventana en 2 regiones, una de dibujado y otra 
 * donde se ubican los botones y etiquetas de información.
 *
 */
import processing.serial.*;

// Declaraciones para graficar funciones...
int cosVal;
int cantValues;
ScrollingFcnPlot f1,fProm,fAct,fMin,fMax;
int grafico_actual;
int grafico_minimo;
int grafico_maximo;
int grafico_promedio;

Serial portread;

//Botones...
RectButton rectMaximo, rectMinimo, rectPromedio, rectActual;;
PFont myFont;

//Etiquetas textuales...
boolean alert = false;
boolean prealert = false;
Label lbl1, lbl2, lbl3, lbl4, lbl5, lbl6, lbl7, lbl8, lbl9, lbl10, lbl11;
Label yVal1,yVal2,yVal3;

//Ventana y viewports...
int pgFunctionViewportWidth = 480;
int pgControlViewportWidth = 120;
int pgViewportsHeight = 240;

void setup() {

  //Se define el tamaño de la ventana de la aplicación... 
  size(650, 240);
  
  portread = new Serial(this,"COM3", 9600); // 0:COM1  1:COM4,9600) portread de lectura, la uso para leer valores de maximo, minimo, promedio, actual.
  //portwrite = new Serial(this,"COM3",9600);        // portwrite de escritura, la uso para setear las funciones que se van a mostrar por el LCD
  
  //Se inicializan los arreglos para almacenar las funciones...
  cantValues = 400;
  f1 = new ScrollingFcnPlot(cantValues,color(0,100,100),-1,1);
  fProm = new ScrollingFcnPlot(cantValues,color(0,100,0),0,50);
  fAct = new ScrollingFcnPlot(cantValues,color(20,20,20),0,50);
  fMax = new ScrollingFcnPlot(cantValues,color(0,0,100),0,50); // height
  fMin = new ScrollingFcnPlot(cantValues,color(50,50,0),0,50);
  
  
  //Se inicializan los botones...
  rectMaximo = new RectButton(pgFunctionViewportWidth+10,10,60,40,color(102),color(50),color(255),"Maximo");
  rectMinimo = new RectButton(pgFunctionViewportWidth+10,60,60,40,color(102),color(50),color(255),"Minimo");
  rectPromedio = new RectButton(pgFunctionViewportWidth+80,10,60,40,color(102),color(50),color(255),"Prom");
  rectActual = new RectButton(pgFunctionViewportWidth+80,60,60,40,color(102),color(50),color(255),"Actual");
  
  
  //Se inicializan los labels...
  lbl1 = new Label(pgFunctionViewportWidth+10,110,color(255),"Status: ");
  lbl2 = new Label(pgFunctionViewportWidth+60,110,color(255),"-");
  lbl3 = new Label(pgFunctionViewportWidth+10,130,color(255),"T.Actual: ");
  lbl4 = new Label(pgFunctionViewportWidth+70,130,color(255)," - °C");
  lbl5 = new Label(pgFunctionViewportWidth+10,150,color(255),"T.Max: ");
  lbl6 = new Label(pgFunctionViewportWidth+70,150,color(255)," - °C");
  lbl7 = new Label(pgFunctionViewportWidth+10,170,color(255),"T.Min: ");
  lbl8 = new Label(pgFunctionViewportWidth+70,170,color(255)," - °C");
  lbl9 = new Label(pgFunctionViewportWidth+10,190,color(255),"T.Prom: ");
  lbl10 = new Label(pgFunctionViewportWidth+70,190,color(255)," - °C");
  //lbl11 = new Label(pgFunctionViewportWidth+10,210,color(255,0,0),"ALERTA!!!");
  
  yVal1 = new Label(10,5,color(255),"C°");
  yVal2 = new Label(480,pgViewportsHeight-25,color(255),"Tiempo");
  yVal3 = new Label(10,pgViewportsHeight-25,color(255),"0");
  
 
  
  //Inicializa el font de la GUI...
  myFont = createFont("FFScala", 14);
  textFont(myFont);
  
}

void draw() {

  
  //Se actualizan las funciones de ejemplo (f1: coseno(x), f2: función que depende de la posición Y del mouse)
  float amount = map(cosVal, 0, cantValues, 0, 2*PI);
  f1.updateValue(cos(amount));
  
  
  //Se incrementa el ángulo de la función coseno...
  cosVal = (cosVal + 1) % cantValues;
  
  //Permite expermientar con la velocidad de scroll al actualizar más lentamente los valores...
  //delay(50);
     
  //Rendering de la interface...
  background(125);
  stroke(0);
  noFill();
 
  //Dibuja las funciones...
  f1.displayIntoRect(30,10,pgFunctionViewportWidth-10,pgViewportsHeight-10);
  fProm.displayIntoRect(30,10,pgFunctionViewportWidth-10,pgViewportsHeight-10);
  fMin.displayIntoRect(30,10,pgFunctionViewportWidth-10,pgViewportsHeight-10);
  fMax.displayIntoRect(30,10,pgFunctionViewportWidth-10,pgViewportsHeight-10);
  fAct.displayIntoRect(30,10,pgFunctionViewportWidth-10,pgViewportsHeight-10);
  
  //Procesa eventos de MouseOver...
  rectMaximo.update();
  rectMinimo.update();
  rectPromedio.update();
  rectActual.update();
  
  //Procesa las entradas (botones)
  if(mousePressed) {
    if(rectMaximo.pressed()) {
      rectMaximo.currentcolor = color(0,100,0);
      lbl2.caption = "LCD: Maximo";
      portread.write(1);
      //port2.write("max");
    } 
    else if(rectMinimo.pressed()) {
      rectMinimo.currentcolor = color(0,100,0);
      lbl2.caption = "LCD: Minimo";
      portread.write(2);
      //port2.write("min");
    }
    else if(rectPromedio.pressed()) {
      rectPromedio.currentcolor = color(0,100,0);
      lbl2.caption = "LCD: Promedio";
      portread.write(3);
      //port2.write("prom");
    }
    else if(rectActual.pressed()) {
      rectActual.currentcolor = color(0,100,0);
      lbl2.caption = "LCD: Actual";
      portread.write(4);
      //port2.write("act");
    }
  }
  
  if((portread.available()>0) && portread.read()==240){
    if(portread.available()>0){
      int actual = portread.read();
      lbl4.caption = actual + " °C";
      grafico_actual = actual;
    }
  }
  if((portread.available()>0) && portread.read()==241){
    if(portread.available()>0){
      int maximo = portread.read();
      lbl6.caption = maximo + " °C";
      grafico_maximo = maximo;
    }
  }
  if((portread.available()>0) && portread.read()==242){
    if(portread.available()>0){
      int minimo = portread.read();
      lbl8.caption = minimo + " °C";
      grafico_minimo = minimo;
    }
  }
  if((portread.available()>0) && portread.read()==243){
    if(portread.available()>0){
      int promedio = portread.read();
      lbl10.caption = promedio + " °C";
      grafico_promedio = promedio;
    }
  }
  //Actualizo valor del grafico.
  fProm.updateValue(grafico_promedio);
  fAct.updateValue(grafico_actual);
  fMin.updateValue(grafico_minimo);
  fMax.updateValue(grafico_maximo);
  
  
  //Dibuja el eje X y el recuadro de los gráficos...
  stroke(0);
  //line(30, pgViewportsHeight/2, pgFunctionViewportWidth-10, pgViewportsHeight/2);
  rect(30,10,pgFunctionViewportWidth-40,pgViewportsHeight-20);
  
  //Se dibujan los botones...
  rectMaximo.display();
  rectMinimo.display();
  rectPromedio.display();
  rectActual.display();
  
  //Se dibuja texto adicional...(labels, etc)
  lbl1.display();
  lbl2.display();
  lbl3.display();
  lbl4.display(); // medidor de actual
  lbl5.display();
  lbl6.display(); // medidor de maximo
  lbl7.display();
  lbl8.display(); // medidor de minimo
  lbl9.display();
  lbl10.display(); // medidor de promedio

//  if (alert) lbl11.display();
  
  yVal1.display();
  yVal2.display();
  yVal3.display();  
}

void mouseReleased()
{

}

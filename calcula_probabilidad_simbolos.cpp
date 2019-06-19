/*
*	Edgard Jose Diaz Tipacamu
*	e.diaz@nartsoft.com.mx
*	
*	Febrero 04 de 2019
*
*       Readme: Compilar este archivo desde consola usando la siguiente sintaxis
*
*       g++ calcula_probabilidades_simbolo.txt -o NAME_EJECUTABLE (usar .exe para windows)
*
*       ejecucion: Para le ejecucion pasar como argumento el nombre o ruta del archivo de texto
*       al que se le desea calcular  la probabilidad de los simbolos, usar la siguinte sintaxis.
*       
*       Ubuntu:  ./NAME_EJECUTABLE  NAME_ARCHIVO.txt
*       windows   NAME_EJECUTABLE   NAME_ARCHIVO.txt
*
*/
#include<iostream>
#include<ctype.h>
using namespace std;
void leer_archivo();
void contar_letras(char simbolo);
void contar_espacion(char simbolo);
void contar_numeros(char simbolo);
void contar_signos(char simbolo);
void calcula_probabilidades();
char simbolo;
int contador = 0, flag = 0, flag1 = 0;
int count_leatters[51];
int letras[51];
#define archivo "casoprueba.txt"
int main(int argc, char const *argv[])
{
	
	for(int i = 0; i <51; i++)
	{
		letras[i] = 0;
	}
	leer_archivo();
    cout<<endl;
    cout<<"Probabilidades de los simbolos del archivo "<<archivo<<"generadas.\n";
    cout<<"El archivo generado se ha guadado en la carpeta donde se encuentra este ejecutable.";
    cout<<endl;
	return 0;
}

void leer_archivo()
{
	FILE *text;

	text = fopen(archivo,"r");
	if(!text)
	{
		cout<<"Archivo no encontrado"<<endl;
		exit(-1);
	}
	else
	{
		while((simbolo = fgetc(text)) != EOF )
		{
    			simbolo = tolower(simbolo);
    			
                if(simbolo >= 97 && simbolo <= 122)
    			{
    				flag1 = 0;
    				flag = 0;
    				contador += 1;
    				contar_letras(simbolo);
    			}
    			else if(simbolo == 10 || simbolo == 32)
    			{
    				contar_espacion(simbolo);
    			}
    			else if(simbolo >= 48 && simbolo <= 57)
    			{
    				flag1 = 0;
    				flag = 0;
    				contador += 1;
    				contar_numeros(simbolo);
    			}
    			else if(simbolo == 33 || simbolo == 34 || simbolo >= 39 && simbolo <= 41 || simbolo >= 44 &&  simbolo <= 47 || simbolo == 58 || simbolo == 59 || simbolo == 63 || simbolo == 95)
    			{
    				flag1 = 0;
    				flag = 0;
    				contador += 1;
    				contar_signos(simbolo);
    			}
            //} 
		}
		if(contador > 0)
		{
			fclose(text);
			calcula_probabilidades();
		}
		
	}
	

}

void calcula_probabilidades()
{
	FILE *salida;
	char ch;
	salida = fopen("result.txt","w");
	float p_letras[51];
    float aux = 0;
	cout<<"Tabla de simbolos"<<endl;
	cout<<"Simbolo\t Probabilidad"<<endl;
	for(int i = 1; i <= 51; i++)
	{
		p_letras[i] = ((float)count_leatters[i]/(float)contador);
		
        aux = aux + p_letras[i];
		if(p_letras[i] !=0)
		{
			ch = char(letras[i]);
			if(ch != 32 && ch != 10)
            {
                cout<<ch<<"\t"<<p_letras[i]<<endl;
                fprintf(salida, "%c%s",ch,"\t");
                fprintf(salida, " %f",p_letras[i] );
                fprintf(salida, "%s","\n" );
            }
            else if(ch == 10)
            {
                cout<<"salto"<<"\t"<<p_letras[i]<<endl;
                fprintf(salida, "%s","salto\t");
                fprintf(salida, "%f",p_letras[i] );
                fprintf(salida, "%s","\n" );
            }
            else
            {
                cout<<"space"<<"\t"<<p_letras[i]<<endl;
                fprintf(salida, "%s","space\t");
                fprintf(salida, "%f",p_letras[i] );
                fprintf(salida, "%s","\n" );
            }

		}
	}
    cout<<"suma "<<aux;
}
void contar_signos(char simbolo)
{
	switch(simbolo)
	{
		case 33: // ! admiracion
			letras[37] = 33;
			count_leatters[37] += 1;
		break;
		case 34: // " Comilla doble
			letras[38] = 34;
			count_leatters[38] += 1;
		break;
		case 39:// ' comilla simple
			letras[39] = 39;
			count_leatters[39] += 1;
		break; 
		case 40: // ( 
			letras[40] = 40;
			count_leatters[40] += 1;
		break;
		case 41: // )
			letras[41] = 41;
			count_leatters[41] += 1;
		break;
		case 44: // , coma
			letras[42] = 44;
			count_leatters[42] += 1;
		break;
		case 45: // - Guion medio
			letras[43] = 45;
			count_leatters[43] += 1;
		break;
		case 46: //  . punto
			letras[44] = 46;
			count_leatters[44] += 1;
		break;
		case 47: // / slash
			letras[45] = 47;
			count_leatters[45] += 1;
		break;
		case 58: // : dos puntos
			letras[46] = 58;
			count_leatters[46] += 1;
		break;
		case 59: // 59 ; punto y coma
			letras[47] = 59;
			count_leatters[47] += 1;
		break;
		case 63: // ? interrogacion
			letras[48] = 63;
			count_leatters[48] += 1;
		break;
		case 95: // _ guion bajo
			letras[49] = 95;
			count_leatters[49] += 1;
		break;
	}
}
/*
*
* en esta seccion del codigo se contabilizan todas las letras de la 'a' a la 'z';
*
*/
    void contar_letras(char simbolo)
    {

    switch(simbolo)
    {
    case 97: //a
    	letras[1] = 97;
        count_leatters[1] += 1;		
    break;
    case 98: //b
    	letras[2] = 98;
        count_leatters[2] += 1;
    break;
    case 99: //c
    	letras[3] = 99;
        count_leatters[3] += 1;
    break;
    case 100: //d
    	letras[4] = 100;
        count_leatters[4] += 1;
    break;	
    case 101: //e
    	letras[5] = 101;
        count_leatters[5] += 1;
    break;
    case 102: //f
    	letras[6] = 102;
        count_leatters[6] += 1;
    break;
    case 103: //g
    	letras[7] = 103;
        count_leatters[7] += 1;
    break;
    case 104: //h
    	letras[8] = 104;
        count_leatters[8] += 1;
    break;
    case 105: //i
    	letras[9] = 105;
        count_leatters[9] += 1;
    break;
    case 106: //j
    	letras[10] = 106;
        count_leatters[10] += 1;
    break;
    case 107: //k
    	letras[11] = 107;
        count_leatters[11] += 1;
    break;
    case 108: //l
    	letras[12] = 108;
        count_leatters[12] += 1;
    break;
    case 109: // m
    	letras[13] = 109;
        count_leatters[13] += 1;
    break;
    case 110: // n
    	letras[14] = 110;
        count_leatters[14] += 1;
    break;
    case 111: // o
    	letras[15] = 111;
        count_leatters[15] += 1;
    break;
    case 112: // p
    	letras[16] = 112;
        count_leatters[16] += 1;
    break;
    case 113: //q
    	letras[17] = 113;
        count_leatters[17] += 1;
    break;
    case 114: //r
    	letras[18] = 114;
        count_leatters[18] += 1;
    break;
    case 115: //s
    	letras[19] = 115;
        count_leatters[19] += 1;
    break;
    case 116: //t
    	letras[20] = 116;
        count_leatters[20] += 1;
    break;
    case 117: //u
    	letras[21] = 117;
        count_leatters[21] += 1;
    break;
    case 118: //v
    	letras[22] = 118;
        count_leatters[22] += 1;
    break;
    case 119: // w
    	letras[23] = 119;
        count_leatters[23] += 1;
    break;
    case 120: // x
    	letras[24] = 120;
        count_leatters[24] += 1;
    break;
    case 121: // y
    	letras[25] = 121;
        count_leatters[25] += 1;
    break;
    case 122: // z
    	letras[26] = 122;
        count_leatters[26] += 1;
    break;
    }
    }
/*
*
* Comienzan los assci pertenecientes a los numeros del 0 al 9.
*/
    void contar_numeros(char simbolo){
    switch(simbolo){
        case 48: // 0
        	letras[27] = 48;
           count_leatters[27] += 1;
        break;
        case 49: // 1
        	letras[28] = 49;
           count_leatters[28] += 1;
        break;
        case 50: // 2
        	letras[29] = 50;
           count_leatters[29] += 1;
        break;
        case 51: // 3
        	letras[30] = 51;
           count_leatters[30] += 1;
        break; 
        case 52: // 4
        	letras[31] = 52;
           count_leatters[31] += 1;
        break;
        case 53: // 5
        	letras[32] = 53;
           count_leatters[32] += 1;
        break;
        case 54: // 6
        letras[33] = 54;
           count_leatters[33] += 1;
        break;
        case 55: // 7
        letras[34] = 55;
           count_leatters[34] += 1;
		break;
        case 56: // 8
        letras[35] = 56;
           count_leatters[35] += 1;
        break;
        case 57: // 9
        letras[36] = 57;
           count_leatters[36] += 1;
        break;}
    }
void contar_espacion(char simbolo)
{
		switch(simbolo)
		{
			case 10: // salto de linea
				if(flag1 == 0)
				{
					contador += 1;
					flag = 0;
					flag1 = 1;
					letras[50] = 32;
					count_leatters[50] += 1;
				}
			break;
			case 32: // Espacio en blanco
				if(flag == 0)
				{
					contador += 1;
					flag = 1;
					flag1 = 0;
					letras[51] = 10;
					count_leatters[51] += 1;
				}
			break;
		}
}

#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");

float x1_k = 0;
float x1_k_1 = 0;
float x2_k = 0;
float x2_k_1 = 0;
float x3_k = 0;
float x3_k_1 = 0;
float x4_k = 0;
float x4_k_1 = 0;
float y1_pos_metre = 0;
float y2_theta_rad = 0;
float commande = 0;

u16 calcul_commande(int y1_pos_num,int y2_theta_num);

float S[5][6] = {
    {0.6300, -0.1206, -0.0008, 0.0086, 0.3658, 0.1200},
    {-0.0953, 0.6935, 0.0107, 0.0012, 0.0993, 0.3070},
    {-0.2896, -1.9184, 1.1306, 0.2351, 1.0887, 2.0141},
    {-3.9680, -1.7733, -0.1546, 0.7222, 3.1377, 1.6599},
    {-80.3092, -9.6237, -14.1215, -23.6260, 0, 0} 
 };

u16 calcul_commande(int y1_pos_num,int y2_theta_num)
{
    y1_pos_metre  = (y1_pos_num-2048.0)*10/2048.0;
    y2_theta_rad = (y2_theta_num-2048.0)*5/2048.0;

    y1_pos_metre  = y1_pos_metre * 0.054 * 2;
    y2_theta_rad = y2_theta_rad * 0.087;

    printk("\npos : %d\nangle : %d\n",(int)y1_pos_metre,(int)y2_theta_rad);

    x1_k_1 = S[0][0]*x1_k + S[0][1]* x2_k + S[0][2]*x3_k + S[0][3]*x4_k +  S[0][4]*y2_theta_rad + S[0][5]*y1_pos_metre ;
    x2_k_1 = S[1][0]*x1_k + S[1][1]* x2_k + S[1][2]*x3_k + S[1][3]*x4_k +  S[1][4]*y2_theta_rad + S[1][5]*y1_pos_metre ;
    x3_k_1 = S[2][0]*x1_k + S[2][1]* x2_k + S[2][2]*x3_k + S[2][3]*x4_k +  S[2][4]*y2_theta_rad + S[2][5]*y1_pos_metre ;
    x4_k_1 = S[3][0]*x1_k + S[3][1]* x2_k + S[3][2]*x3_k + S[3][3]*x4_k +  S[3][4]*y2_theta_rad + S[3][5]*y1_pos_metre ;

    commande = (S[4][0]*(x1_k)+ S[4][1]*x2_k + S[4][2]*x3_k + S[4][3]*x4_k);
    x1_k=x1_k_1;
    x2_k=x2_k_1;
    x3_k=x3_k_1;
    x4_k=x4_k_1;

    if(commande > 9.5) commande=9.5;
    if(commande <-9.5) commande=-9.5;

    if(y2_theta_rad > 0.32) commande = 0;
    if(y2_theta_rad < -0.32) commande = 0;

    if(y1_pos_metre > 8) commande = 0;
    if(y1_pos_metre < -8) commande = 0;

    return (commande*2048/10)+2048;
}

EXPORT_SYMBOL(calcul_commande);
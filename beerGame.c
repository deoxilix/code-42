#include <stdio.h>
#include <stdlib.h>

int back, i, n[11], months;
float store;
static float flag=0;
static int s;


                                                                                //FactoryCode
int factory(){
    int inventory = 0, j = 40;
                                                                                //Output::factory
    for (i = 0; i <= months; i++){

        if ((inventory+j)<=200)
            inventory+=j;
        else
            inventory=200;

        printf  ("\n\nMONTH %d", i+1);
        printf ("\ninventory this month: %d", inventory);
        printf ("\nIncoming order: %d", n[i]);

        if (inventory<n[i]){
           back=(n[i]-inventory);
           inventory=0;
           printf ("\nhow many do you want to manufacture [<20]: ");
           scanf ("%d", &j);
           store=j;
           printf ("BACKLOG:%d\nstore:%f\ninventory:%d", back, store, inventory);
           }

        else
            {printf ("\nhow many do you want to manufacture[<20]: ");
            scanf ("%d", &j);
            store=(inventory-n[i])*0.5;
            inventory-=n[i], back=0;
            printf ("BACKLOG:%d\nstore:%f", back, store);}

        flag+=(back+store);


    }
    printf ("\n\nSCORE: %f", flag);
    return 0;
}


                                                                                //DistributorWholesalerRetailerCode
 int distributor_wholesaler_retailer(){
    int inventory[11], j=0;
                                                                                //Inventory::defense::0
    for(i=0; i<= months; i++){
      if(i<=0)
      inventory[i]=40;
      else
      inventory[i]=0;
      }

    for (i=0;i<=months;i++){

        printf  ("\n\nMONTH %d", i+1);
        printf ("\nInventory this month: %d", inventory[i]);
        printf ("\nIncoming order: %d", n[i]);
        // printf ("\nexpected arrivals: %d", inventory[i+1]);

               if (inventory[i]>n[i]){
                                back=0;
                                inventory[i]=inventory[i]-n[i];
                                inventory[i+1]+=inventory[i];
                                store=0.5*inventory[i];
                                printf("\nBACKLOG:%d\nstore:%f", back, store);
                                }
               else{
                    back=n[i]-inventory[i];
                    inventory[i]=0;
                    store=0;
                    printf("\nBACKLOG:%d\nstore:%f", back, store);
                    }
        flag+=(back+store);

        printf ("\nPlace your order: ");
        scanf ("%d", &j);
        inventory[i+1]+=j;
                     }

        printf ("\nSCORE: %f", flag);
        return 0;
        }

void roleSwitch(){                                                              //role switch: duh!!
  switch(s){

        case 1:
              factory();
              break;

        case 2:
              distributor_wholesaler_retailer();
              break;

        case 3:
              distributor_wholesaler_retailer();
              break;

        case 4:
              distributor_wholesaler_retailer();
              break;

        default:
              roleSwitch();
              break;
              };
            }

                                                                                //COMMAND::FUNC::MAIN
int main(void){
                                                                                //INPUT::Coordinator
    printf ("Type in number of months, you want the game to be of: ");
    scanf("%d", &months);

    printf ("Type in %d orders: \n", months);
    for(--months, i=0; i <= months ; scanf ("%d", &n[i]), i++){}
                                                                                //Display.switch.sector
        system("cls");
        system ("color 3f");                                                    //Colour.Code

                                                                                //INPUT::Player::GameBegins
        printf ("\t\t* T H E  b E E R  G A M E *");
        printf ("\n\nPlease enter,\n1 for factory,\n2 for distributor,\n3 for wholesaler,\n4 for retailer:\n");
        scanf ("%d", &s);

        roleSwitch();

        for(;getchar(););                                                       //KillSwitch::[0]
    }

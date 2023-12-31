#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#define MAX_NOME 50
#define MAX_DATA_NASCIMENTO 11
#define MAX_PLANO_SAUDE 50
#define MAX_NUM_CARTEIRINHA 20
#define MAX_CPF 12
#define MAX_USUARIO 20
#define MAX_SENHA 20

	typedef struct {
    	char nome[MAX_NOME];
    	char dataNascimento[MAX_DATA_NASCIMENTO];
    	char planoSaude[MAX_PLANO_SAUDE];
    	char numeroCarteirinha[MAX_NUM_CARTEIRINHA];
    	char cpf[MAX_CPF];
    	char usuario[MAX_USUARIO];
    	char senha[MAX_SENHA];
    } Cadastro;

	int especialidade;
	int escolhaEspecialidade;
	int escolhaHorario;
	int dia_hora;
	int deseja;

    char resposta[2];
    int loggedIn = 0;
    int opcao;
    char usuario[20];
    char senha[20];
    
    int opcaod, exames, gera;  
    
    char ESPEC, DH, EXA, OPCd;

	void realizarCadastro(Cadastro *cadastro) {
    printf("---------------------------------------\n");
    printf("                CADASTRO               \n");
    printf("---------------------------------------\n");
    printf("Nome completo: ");
    scanf("%s", cadastro->nome);
    gets(cadastro->nome);

    printf("Data de Nascimento: ");
    scanf("%s", cadastro->dataNascimento); 
    gets(cadastro->dataNascimento);

    printf("Qual o seu plano de saude? ");
    scanf("%s", cadastro->planoSaude);
    gets(cadastro->planoSaude);

    printf("Numero da carteirinha do plano de saude: ");
    scanf("%s", cadastro->numeroCarteirinha);
    gets(cadastro->numeroCarteirinha);

    printf("CPF: ");
    scanf("%s", cadastro->cpf);
    gets(cadastro->cpf);

    printf("---------------------------------------\n");
    printf("              CRIAR LOGIN              \n");
    printf("---------------------------------------\n");
    printf("Usuario: ");
    scanf("%s", cadastro->usuario);
    gets(cadastro->usuario);

    printf("Senha: ");
    scanf("%s", cadastro->senha);
    gets(cadastro->senha);

    printf("Cadastro realizado com sucesso!\n");
}

int realizarLogin(Cadastro* cadastro) {
    char usuario[20];
    char senha[20];

    printf("---------------------------------------\n");
    printf("                 LOGIN                 \n");
    printf("---------------------------------------\n");
    printf("Usuario: ");
    scanf("%s", usuario);
    gets(usuario);

    printf("Senha: ");
    scanf("%s", senha);
    gets(senha);

    if (strcmp(usuario, cadastro->usuario) == 0 && strcmp(senha, cadastro->senha) == 0) {
        return 1;
    } else {
        printf("Dados incorretos | Recomece a operação.\n");
        return 0;
    }
}

void servico(){
	
	printf("\nQual o servico você deseja realizar?\n");
    printf("[1] - Marcar Consulta\n");
    printf("[2] - Agendar Exames\n");
    printf("[3] - Historico de Consultas/Exames\n");
    printf("[4] - Visualizar Resultados dos Exames\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
	system("cls");

} 

	void desejo(){
		
		printf("Deseja realizar outro servico?\n");
		printf("[1] - Sim\n");
		printf("[2] - Nao\n");
		printf("Opcao: ");
		scanf("%d", &deseja);
		
		if(deseja == 1){
			deseja = 1;
		}
		else{
			if(deseja == 2){
				system("cls");
				deseja = 2;
				printf("\n");
				printf("---------------------------------------\n");
    			printf("       OBRIGADA PELA PREFERENCIA       \n");
    			printf("---------------------------------------\n");
				printf("\n");
				system("pause");
				exit(0);
			}
		}
	}

int main() {

    char resposta[2];
    Cadastro cadastro;
    int loggedIn = 0;

    printf("---------------------------------------\n");
	printf("          Seja bem-vindo(a) ao         \n");
	printf("  Sistema de Agendamento de Consultas  \n");
	printf("---------------------------------------\n");
    printf("Voce possui um cadastro? [S/N]: ");
    fgets(resposta, sizeof(resposta), stdin);
    resposta[strcspn(resposta, "\n")] = '\0';

    if (strcmp(resposta, "N") == 0 || strcmp(resposta, "n") == 0) {
        realizarCadastro(&cadastro);
        loggedIn = realizarLogin(&cadastro);
    } else {
        loggedIn = realizarLogin(&cadastro);
        loggedIn = 1; 
    }

	system("cls");

    if (loggedIn) {
           
        int codigo = 1;
   		deseja = 1;
   		
   		do{
   		
            servico();

            switch (opcao){
            	
                case 1:
                	
	    			printf("-------------------------------------\n");
					printf("            MARCAR CONSULTA          \n");
					printf("-------------------------------------\n");
	
	    			printf("Qual a especialidade da sua consulta?\n");
    				printf("[1] - Gastroenterologia\n");
   					printf("[2] - Nefrologista\n");
    				printf("[3] - Pneumologista\n");
    				
    				printf("opcao: ");
    				scanf("%d", &escolhaEspecialidade);	
	    
    				if(escolhaEspecialidade<1 || escolhaEspecialidade>3){
    					system("cls");
    	    			printf("-------------------------------------\n");
						printf("Opcao Invalida, tente novamente\n");
					}
        			else{
	
    	    			printf("\nDatas e horarios disponiveis para sua consulta:\n");
    					printf("Selecione a melhor opcao para voce:\n");
    					printf("[1] - 17/07/23 as 14h\n");
    					printf("[2] - 18/07/23 as 16h\n");
    					printf("[3] - 19/07/23 as 14h\n");
    					printf("[4] - 20/07/23 as 16h\n");
    					
    					printf("opcao: ");
    					scanf("%d", &escolhaHorario);
    	
    	    			if(escolhaHorario<1 || escolhaHorario>4){
    	        			system("cls");
    	  					printf("-------------------------------------\n");
    	   					printf("Opcao Invalida, recomece a operacao\n");
						} 
    	  				else{
    	  					printf("-------------------------------\n");
          					printf("Consulta marcada com sucesso!\n");
          					printf("\n");
	    					
    					switch(escolhaEspecialidade){
        				case 1:
        					ESPEC = 1;
            				printf("Seu medico gastroenterologista e DR. ROBERTO TEIXEIRA\n");
            				break;
        				case 2:
        					ESPEC = 2;
            				printf("Seu medico nefrologista e DR. EVANDRO QUEIROZ\n");
            				break;
        				case 3:
        					ESPEC = 3;
            				printf("Seu medico pneumologista e DR. FABIANO COSTA\n");
            				break;
        				default:
            				printf("Opção inválida\n");
            				return 0;
    					}
    
    					switch(escolhaHorario) {
        					case 1:
        						DH = 1;
            					printf("Data e Horario da sua consulta: Dia 17/07/23 as 14h\n");
            					break;
        					case 2:
        						DH = 2;
            					printf("Data e Horario da sua consulta: Dia 18/07/23 as 16h\n");
            					break;
        					case 3:
        						DH = 3;
            					printf("Data e Horario da sua consulta: Dia 19/07/23 as 14h\n");
            					break;
        					case 4:
        						DH = 4;
            					printf("Data e Horario da sua consulta: Dia 20/07/23 as 16h\n");
           						break;
        					default:
            					printf("Opcao invalida\n");
            					return 0;
    					}	
    
				printf("-------------------------------------\n");
	     				      
	     		printf("Codigo da consulta: %d\n", codigo);
        		codigo++;
        		
        		printf("-------------------------------------\n");
	     				      
	      		desejo();
	      		system("cls");
                		}
        			}  
		
           		break;
      
                case 2:
         
                    printf("-------------------------------------------\n");
     				printf("               AGENDAR EXAMES              \n");
     				printf("-------------------------------------------\n");
     				printf(" Digite o numero do exame que deseja fazer:\n");
     				printf("[1] Exame de sangue\n");
     				printf("[2] Exame de urina\n");
     				printf("[3] Endoscopia\n");
    				printf("[4] Colonoscopia\n");
    				printf("[5] Ultrassonografia\n");
     				printf("[6] Biopsia\n");
     				printf("[7] Tomografia\n");
     				printf("[8] Radiografia\n");
     				printf("opcao: ");
     				scanf("%d",&exames);
         
                    if (exames<1 || exames>8){
                        system("cls");
                        printf("-------------------------------------\n");
    	    			printf("Opcao Invalida, recomece a operacao\n");
       				}
        			else{
        					
            			printf("\nDatas e horarios disponiveis para sua consulta:\n");
    					printf("Selecione a melhor opcao para voce:\n");
     					printf ("[1] - 10/07/2023 às 10:00 horas.\n ");
     					printf ("[2] - 10/07/2023 às 12:00 horas.\n ");
     					printf ("[3] - 10/07/2023 às 14:00 horas.\n ");
     					printf ("[4] - 11/07/2023 às 10:00 horas.\n ");
     					printf ("[5] - 11/07/2023 às 12:00 horas.\n ");
     					printf ("[6] - 11/07/2023 às 14:00 horas.\n ");
     					printf ("[7] - 12/07/2023 às 10:00 horas.\n ");
     					printf ("[8] - 12/07/2023 às 12:00 horas.\n ");
     					printf ("[9] - 12/07/2023 às 14:00 horas.\n ");
     					printf("opcao: ");
     					scanf ("%d", &opcaod);
            
           				if (opcaod<1 || opcaod>9){
           					printf("-------------------------------------\n");
    	    				printf("Opcao Invalida, recomece a operacao\n"); 
   						}
    					else{
    						printf("-------------------------------------\n");
    						printf("Exame agendado com sucesso!\n");
        					printf("\nVoce escolheu o exame:");
        					
        					switch(exames){
        					case 1:
        						EXA = 1;
            					printf("EXAME DE SANGUE\n");
            					break;
        					case 2:
        						EXA = 2;
            					printf("EXAME DE URINA\n");
            					break;
        					case 3:
        						EXA = 3;
            					printf("ENDOSCOPIA\n");
            					break;
        					case 4:
        						EXA = 4;
            					printf("COLONOSCOPIA\n");
           						break;
           					case 5:
           						EXA = 5;
           						printf("ULTRASSONOGRAFIA\n");
								break;	
							case 6:
								EXA = 6;
								printf("ULTRASOM\n");
								break;
							case 7:
								EXA = 7;
								printf("TOMOGRAFIA\n");
								break;
							case 8:
								EXA = 8;
								printf("RADIOGRAFIA\n");
								break;
        					default:
            					printf("Opcao invalida\n");
            					return 0;
    						}	
       						
        					printf("Exame agendado para o ");
        					
        					switch(opcaod){
        					case 1:
        						OPCd = 1;
            					printf("dia 10/07/2023 as 10:00 horas.\n");
            					break;
        					case 2:
        						OPCd = 2;
            					printf("dia 10/07/2023 as 12:00 horas.\n");
            					break;
        					case 3:
        						OPCd = 3;
            					printf("dia 10/07/2023 as 14:00 horas.\n");
            					break;
        					case 4:
        						OPCd = 4;
            					printf("dia 11/07/2023 as 10:00 horas.\n");
           						break;
           					case 5:
           						OPCd = 5;
           						printf("dia 11/07/2023 as 12:00 horas.\n");
								break;	
							case 6:
								OPCd = 6;
								printf("dia 11/07/2023 as 14:00 horas.\n");
								break;
							case 7:
								OPCd = 7;
								printf("dia 12/07/2023 as 10:00 horas.\n");
								break;
							case 8:
								OPCd = 8;
								printf("dia 12/07/2023 as 12:00 horas.\n");
								break;
							case 9:
								OPCd = 9;
								printf("dia 12/07/2023 às 14:00 horas.\n");
								break;
        					default:
            					printf("Opcao invalida\n");
            					return 0;
    						}

     						printf ("\nTrazer as documentacoes necessarias para o exame na data marcada.\n ");
        				
        					printf("-------------------------------------\n");
	     		
	     					printf("Codigo do exame: %d\n", codigo);
        					codigo++;
        					
        					printf("-------------------------------------\n");
	     				      
	      					desejo();
	      					system("cls");
                		}
        			}  
	
				break;
 
                case 3:
                    printf("---------------------------------------\n");
  					printf("     HISTORICO DE CONSULTAS/EXAMES     \n");
    				printf("---------------------------------------\n");

    				printf("\nSuas consultas sao:\n\n");
    				
    				printf("Consulta: %d\n", ESPEC);
    				switch(ESPEC){
        				case 1:
            				printf("DR. ROBERTO TEIXEIRA - Gastroenterologista\n");
            				break;
        				case 2:
            				printf("DR. EVANDRO QUEIROZ - Nefrologista\n");
            				break;
        				case 3:
            				printf("DR. FABIANO COSTA - Nefrologista\n");
            				break;
        				default:
            				printf("Nenhuma informacao cadastrada\n");
    					}
    					
    				printf("Data e Horario: %d\n", DH);
    				
    				switch(DH){
        				case 1:
            				printf("Data e Horario da sua consulta: Dia 17/07/23 as 14h\n");
            				break;
        				case 2:
            				printf("Data e Horario da sua consulta: Dia 18/07/23 as 16h\n");
            				break;
        				case 3:
            				printf("Data e Horario da sua consulta: Dia 19/07/23 as 14h\n");
            				break;
        				case 4:
            				printf("Data e Horario da sua consulta: Dia 20/07/23 as 16h\n");
           					break;
        				default:
            				printf("Nenhuma informacao cadastrada\n");
    					}	
							
    				printf("\nSeus exames sao:\n\n");
    			
    				printf("Exame: %d\n", exames);
    				
    				switch(EXA){
        				case 1:
            				printf("EXAME DE SANGUE\n");
            				break;
        				case 2:
            				printf("EXAME DE URINA\n");
            				break;
        				case 3:
            				printf("ENDOSCOPIA\n");
            				break;
        				case 4:
            				printf("COLONOSCOPIA\n");
           					break;
           				case 5:
           					printf("ULTRASSONOGRAFIA\n");
							break;	
						case 6:
							printf("ULTRASOM\n");
							break;
						case 7:
							printf("TOMOGRAFIA\n");
							break;
						case 8:
							printf("RADIOGRAFIA\n");
							break;
        				default:
            				printf("Nenhuma informacao cadastrada\n");
    					}	
    				
    				printf("Data e Horario: %d\n", opcaod);
    				
    				switch(OPCd){
        					case 1:
            					printf("Dia 10/07/2023 as 10:00 horas.\n");
            					break;
        					case 2:
            					printf("Dia 10/07/2023 as 12:00 horas.\n");
            					break;
        					case 3:
            					printf("Dia 10/07/2023 as 14:00 horas.\n");
            					break;
        					case 4:
            					printf("Dia 11/07/2023 as 10:00 horas.\n");
           						break;
           					case 5:
           						printf("Dia 11/07/2023 as 12:00 horas.\n");
								break;	
							case 6:
								printf("Dia 11/07/2023 as 14:00 horas.\n");
								break;
							case 7:
								printf("Dia 12/07/2023 as 10:00 horas.\n");
								break;
							case 8:
								printf("Dia 12/07/2023 as 12:00 horas.\n");
								break;
							case 9:
								printf("Dia 12/07/2023 às 14:00 horas.\n");
								break;
        					default:
            					printf("Nenhuma informacao cadastrada\n");
    						}
    				printf("\n");
                    desejo();
	      			system("cls");
                break;

                case 4:
                	printf("----------------------------------------\n");
  					printf("          RESULTADO DOS EXAMES          \n");
    				printf("----------------------------------------\n");
    				printf("\n");
                	printf("\nDigite o codigo da Consulta/Exame:");
    				scanf("%d", &codigo);
    				
                    if (codigo%2==0){
 						printf ("\n Exame com alteracoes. Recomenda-se passar o mesmo por avaliacao medica\n\n");
 					}
					else{
 						printf ("\n Exame sem nenhuma alteracao\n\n");
 					}
 					printf("\n");
                    desejo();
	      			system("cls");
                break;
 
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
    	} while (strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0);
    	
 }
    printf("\nObrigado pela Preferência!\n");
    return 0;
}
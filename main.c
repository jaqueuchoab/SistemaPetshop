#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structs
typedef struct cadastro_pet {
  int id;
  char nome[21];
  char tutor[21];
  char endereco[21];
  char cor[21];
  char raca[21];
  char tipo[21];
  char idade[21];
  char contraindicacoes[100];
} Pet;

typedef struct cadastro_atendimento {
  int id;
  int opcao;
} Servico;

// Protótipos das funções
void cabecalhoPetShop();
void menuPrincipalPetshop();
FILE *cadastroPetFunction();
void povoaStructCadastroPet(FILE *cadastroPet, Pet pet);
FILE *cadastroAtendimento();
void atendimentoCase(FILE *cadastroAtendimento);
void alterarPet();
// Refatorar a função alteraPet();
void alteracaoCases(int opcao);
void excluirAtendimento();
void excluirAnimal();
void pesquisarAnimal();
void sairPet();
void listarAnimal();
void listarAtendimentos();
void flush_in();

int main(void) {
  // Limpar terminal - início
  system("clear");
  // Chamando menu
  menuPrincipalPetshop();
  return 0;
}

// Construção das funções
void cabecalhoPetShop() {
  printf("\t\t\t\t\t   PET SHOP BOM PREÇO \n ");
  printf("\t\t\t\t  Seu animal em boas mãos!\n\n");
}

void menuPrincipalPetshop() {
  int opcao, tipo;

  cabecalhoPetShop();
  printf("\t\t\t====================================\n");
  printf("\t\t\t||                                ||\n");
  printf("\t\t\t||    1 - Cadastrar Pet           ||\n");
  printf("\t\t\t||    2 - Cadastrar Tutor         ||\n");
  printf("\t\t\t||    3 - Cadastrar Atendimento   ||\n");
  printf("\t\t\t||    4 - Alterar Cadastro Pet    ||\n");
  printf("\t\t\t||    5 - Excluir Atendimento     ||\n");
  printf("\t\t\t||    6 - Excluir Animal          ||\n");
  printf("\t\t\t||    7 - Pesquisar Animais       ||\n");
  printf("\t\t\t||    8 - Listar Animais          ||\n");
  printf("\t\t\t||    9 - Listar Atendimentos     ||\n");
  printf("\t\t\t||    10 - Sair                   ||\n");
  printf("\t\t\t||                                ||\n");
  printf("\t\t\t====================================\n");
  printf("\n");

  // Campo para escolha de serviço
  printf("\t\t\tPor favor, selecione uma opcao: ");
  scanf("%d", &opcao);

  // Manipulação do menu
  switch (opcao) {
  case 1:
    setbuf(stdin, NULL);
    cadastroPetFunction();
    break;
  case 2:
    // Cadastrar tutor
    break;
  case 3:
    // Cadastrar Atendimento
    cadastroAtendimento();
    break;
  case 4:
    alterarPet();
    break;
  case 5:
    // Excluir Atendimento
    excluirAtendimento();
    break;
  case 6:
    excluirAnimal();
    break;
  case 7:
    // Pesquisar Animais
    pesquisarAnimal();
    break;
  case 8:
    // Listar Animais
    listarAnimal();
    break;
  case 9:
    // Listar Atendimentos
    listarAtendimentos();
    break;
  case 10:
    // Sair
    sairPet();
    break;
  default:
    printf("Opção inválida!");
    menuPrincipalPetshop();
  }
}

void povoaStructCadastroPet(FILE *cadastroPet, Pet pet) {
  printf("\n");
  printf("\t\t\t---------- Cadastrar Pet -----------\n");
  printf("\t\t\tID: ");
  scanf("%d", &pet.id);
  flush_in();

  printf("\t\t\tNome do pet: ");
  fgets(pet.nome, 21, stdin);

  printf("\t\t\tNome do tutor: ");
  fgets(pet.tutor, 21, stdin);

  printf("\t\t\tEndereço: ");
  fgets(pet.endereco, 21, stdin);

  printf("\t\t\tRaça: ");
  fgets(pet.raca, 21, stdin);

  printf("\t\t\tCor: ");
  fgets(pet.cor, 21, stdin);

  printf("\t\t\tTipo: ");
  fgets(pet.tipo, 21, stdin);

  printf("\t\t\tContraindicações: ");
  fgets(pet.contraindicacoes, 50, stdin);

  printf("\t\t\tIdade: ");
  scanf("%s", pet.idade);
  flush_in();

  fwrite(&pet, sizeof(Pet), 1, cadastroPet);
}

FILE *cadastroPetFunction() {
  Pet pet;
  int seguir;
  FILE *cadastroPet = fopen("cadastrosPet.bin", "a+b");
  if (cadastroPet == NULL) {
    printf("Erro ao abrir o arquivo!");
  } else {
    do {
      povoaStructCadastroPet(cadastroPet, pet);
      printf("\n\t\t\tDeseja cadastrar outro pet? (S:1/N:0): ");
      scanf("%d", &seguir);
      setbuf(stdin, NULL);
    } while (seguir != 0);
    fclose(cadastroPet);
    system("clear"); // limpar terminal
    menuPrincipalPetshop();
  }

  return cadastroPet;
}

// CADASTRAR TUTOR FUNÇÃO AQUI

void atendimentoCase(FILE *cadastroAtendimento) {
  int opcao;
  Servico atendimento;

  printf("\n\t\t\tInforme o ID de cadastro do seu Pet: ");
  scanf("%d", &atendimento.id);

  printf("\n\t\t\tIndique qual atendimento você deseja:\n");
  printf("\t\t\t====================================\n");
  printf("\t\t\t||                                ||\n");
  printf("\t\t\t||    1 - Banho                   ||\n");
  printf("\t\t\t||    2 - Banho e Tosa            ||\n");
  printf("\t\t\t||    3 - Hidratação              ||\n");
  printf("\t\t\t||    4 - Desembaraçamento        ||\n");
  printf("\t\t\t||    5 - Limpeza de ouvido       ||\n");
  printf("\t\t\t||    6 - Corte de unhas          ||\n");
  printf("\t\t\t||    7 - Escovação de dentes     ||\n");
  printf("\t\t\t||                                ||\n");
  printf("\t\t\t====================================\n");

  // Campo para escolha de serviço
  printf("\t\t\tPor favor, selecione uma opcao: ");
  scanf("%d", &atendimento.opcao);
  printf("\n");
  fwrite(&atendimento, sizeof(Servico), 1, cadastroAtendimento);
}

FILE *cadastroAtendimento() {
  int seguir;
  FILE *cadastroAtendimento = fopen("cadastroAtendimento.bin", "a+b");
  if (cadastroAtendimento == NULL) {
    printf("Erro ao abrir o arquivo!");
  } else {

    do {
      atendimentoCase(cadastroAtendimento);
      printf("\n\t\t\tDeseja cadastrar outro atendimento? (S:1/N:0): ");
      scanf("%d", &seguir);
      setbuf(stdin, NULL);
    } while (seguir != 0);

    fclose(cadastroAtendimento);
    system("clear"); // limpar terminal
    menuPrincipalPetshop();
  }

  return cadastroAtendimento;
}

void alterarPet() {
  int id, EOF_ARQ, voltar, idNonexistent, opcao;
  idNonexistent = 0;
  Pet pet;
  printf("\t\t\tInforme o ID do Pet que dejesa alterar: ");
  scanf("%d", &id);

  FILE *cadastroPet = fopen("cadastrosPet.bin", "a+b");
  FILE *temporario = fopen("tempAlterar.bin", "a+b");

  while (!feof(cadastroPet)) {
    EOF_ARQ = fread(&pet, sizeof(Pet), 1, cadastroPet);
    if (ferror(cadastroPet)) {
      printf("\n\t\t\tErro na leitura do arquivo");
    } else {
      if (id != pet.id) {
        if (EOF_ARQ != 0) {
          fwrite(&pet, sizeof(Pet), 1, temporario);
        }
      } else {
        if (id == pet.id && EOF_ARQ != 0) {
          idNonexistent = 1;
          printf("\n\t\t\tRegistro atual: \n");

          printf("\t\t\tID: %d\n", pet.id);
          printf("\t\t\tNome do Pet: %s", pet.nome);
          printf("\t\t\tNome do Tutor: %s", pet.tutor);
          printf("\t\t\tEndereço: %s", pet.endereco);
          printf("\t\t\tRaça: %s", pet.raca);
          printf("\t\t\tCor: %s", pet.cor);
          printf("\t\t\tTipo: %s", pet.tipo);
          printf("\t\t\tContraindicações: %s", pet.contraindicacoes);
          printf("\t\t\tIdade: %s", pet.idade);
          printf("\n\n");
          printf("\t\t\tO que você deseja alterar neste cadastro?\n");
          printf("\t\t\t====================================\n");
          printf("\t\t\t||                                ||\n");
          printf("\t\t\t||    1 - Nome do Pet             ||\n");
          printf("\t\t\t||    2 - Nome do Tutor           ||\n");
          printf("\t\t\t||    3 - Endereço                ||\n");
          printf("\t\t\t||    4 - Raça                    ||\n");
          printf("\t\t\t||    5 - Cor                     ||\n");
          printf("\t\t\t||    6 - Tipo                    ||\n");
          printf("\t\t\t||    7 - Contraindicações        ||\n");
          printf("\t\t\t||    8 - Idade                   ||\n");
          printf("\t\t\t||                                ||\n");
          printf("\t\t\t====================================\n");
          printf("\n");
          printf("\t\t\tSelecione uma opção: ");
          scanf("%d", &opcao);
          flush_in();

          switch (opcao) {
          case 1:
            printf("\t\t\tDigite o novo nome do Pet:");
            fgets(pet.nome, 21, stdin);
            flush_in();
            break;
          case 2:
            printf("\t\t\tDigite o novo nome do Tutor:");
            fgets(pet.tutor, 21, stdin);
            flush_in();
            break;
          case 3:
            printf("\t\t\tDigite o novo endereço:");
            fgets(pet.endereco, 21, stdin);
            flush_in();
            break;
          case 4:
            printf("\t\t\tDigite a nova raça Pet:");
            fgets(pet.raca, 21, stdin);
            flush_in();
            break;
          case 5:
            printf("\t\t\tDigite a nova cor do Pet:");
            fgets(pet.cor, 21, stdin);
            flush_in();
            break;
          case 6:
            printf("\t\t\tDigite o novo tipo:");
            fgets(pet.tipo, 21, stdin);
            flush_in();
            break;
          case 7:
            printf("\t\t\tDigite a contradição do Pet:");
            fgets(pet.contraindicacoes, 50, stdin);
            flush_in();
            break;
          case 8:
            printf("\t\t\tDigite a nova idade do Pet:");
            scanf("%s", pet.idade);
            flush_in();
            break;
          default:
            printf("Opção inválida!");
          }
          fwrite(&pet, sizeof(Pet), 1, temporario);
        }
      }
    }
  }

  // Verificando se nenhum Id foi encontrado ou houve alguma digitação errada
  if (idNonexistent == 0) {
    printf("\n\t\t\tID não cadastrado em nossos registros!");
    printf("\n\n\t\t\t1 - Cadastrar ID");
    printf("\n\t\t\t2 - Tentar Alteração Novamente");
    printf("\n\t\t\t3 - Voltar ao Menu Principal");
    printf("\n\n\t\t\tSelecione uma opção: ");
    scanf("%d", &voltar);
    if (voltar == 1) {
      system("clear");
      cabecalhoPetShop();
      cadastroPetFunction();
    } else if (voltar == 2) {
      system("clear");
      cabecalhoPetShop();
      alterarPet();
    } else {
      system("clear");
      menuPrincipalPetshop();
    }
  }

  if (ferror(temporario)) {
    printf("\n\t\t\tErro ao excluir\n");
  } else {
    fclose(temporario);
    fclose(cadastroPet);

    remove("cadastrosPet.bin");
    rename("tempAlterar.bin", "cadastrosPet.bin");
  }

  printf("\n\t\t\tDeseja alterar outro cadastro? (S:1/N:0): ");
  scanf("%d", &opcao);
  system("clear");
  opcao == 1 ? alterarPet() : menuPrincipalPetshop();
}

void alteracaoCases(int opcao) {
  switch (opcao) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  default:
    printf("Opção inválida!");
  }
}

void excluirAtendimento() {
  FILE *cadastroAtendimento_Pet = fopen("cadastroAtendimento.bin", "a+b");
  FILE *temporario = fopen("temp.bin", "a+b");

  int id, EOF_ARQ;
  Servico atendimento;

  printf("\t\t\tCódigo de ID do Pet que dejesa excluir: ");
  scanf("%d", &id);

  while (!feof(cadastroAtendimento_Pet)) {
    EOF_ARQ = fread(&atendimento, sizeof(Servico), 1, cadastroAtendimento_Pet);
    if (id != atendimento.id) {
      if (EOF_ARQ != 0) {
        fwrite(&atendimento, sizeof(Servico), 1, temporario);
      }
    } else {
      printf("\n\t\t\tExcluido com sucesso!");
    }
  }

  if (ferror(temporario)) {
    printf("\n\t\t\tErro ao excluir\n");
  } else {
    fclose(temporario);
    fclose(cadastroAtendimento_Pet);

    remove("cadastroAtendimento.bin");
    rename("temp.bin", "cadastroAtendimento.bin");

    int opcao;
    printf("\n\t\t\tDeseja excluir outro atendimento? (S:1/N:0): ");
    scanf("%d", &opcao);
    system("clear");
    opcao == 1 ? excluirAtendimento() : menuPrincipalPetshop();
  }
}

void excluirAnimal() {
  FILE *cadastroPet;
  FILE *temporario;
  cadastroPet = fopen("cadastrosPet.bin", "r");
  temporario = fopen("temp.txt", "a");

  Pet registros;
  int id;
  printf("\t\t\tCódigo que dejesa excluir: ");
  scanf("%d", &id);

  while (fread(&registros, sizeof(Pet), 1, cadastroPet) == 1) {
    if (id == registros.id) {
      continue;
    } else {
      fwrite(&registros, sizeof(Pet), 1, temporario);
    }
  }
  if (ferror(temporario)) {
    printf("\n\t\t\tErro ao excluir\n");
  } else {
    printf("\n\t\t\tExcluido com sucesso!");
  }
  fclose(temporario);
  fclose(cadastroPet);

  remove("cadastrosPet.bin");
  rename("temp.txt", "cadastrosPet.bin");

  int opcao;
  printf("\n\t\t\tDeseja excluir outro atendimento? (S:1/N:0): ");
  scanf("%d", &opcao);
  system("clear");
  opcao == 1 ? excluirAnimal() : menuPrincipalPetshop();
}

void pesquisarAnimal() {
  Pet pet;
  int id, voltar, EOF_ARQ, idNonexistent;
  FILE *cadastroPet = fopen("cadastrosPet.bin", "a+b");

  printf("\n\t\t\tInforme o ID que deseja pesquisar: ");
  scanf("%d", &id);
  printf("\n");

  while (!feof(cadastroPet)) {
    EOF_ARQ = fread(&pet, sizeof(Pet), 1, cadastroPet);
    if (ferror(cadastroPet)) {
      printf("\n\t\t\tErro na leitura do arquivo");
    } else {
      if (id == pet.id && EOF_ARQ != 0) {
        idNonexistent = 1;
        printf("\t\t\tID: %d\n", pet.id);
        printf("\t\t\tNome do Pet: %s", pet.nome);
        printf("\t\t\tNome do Tutor: %s", pet.tutor);
        printf("\t\t\tEndereço: %s", pet.endereco);
        printf("\t\t\tRaça: %s", pet.raca);
        printf("\t\t\tCor: %s", pet.cor);
        printf("\t\t\tTipo: %s", pet.tipo);
        printf("\t\t\tContraindicações: %s", pet.contraindicacoes);
        printf("\t\t\tIdade: %s", pet.idade);
        printf("\n\n");
      }
    }
  }
  // Verificando se nenhum Id foi encontrado ou houve alguma digitação errada
  if (idNonexistent == 0) {
    printf("\n\t\t\tID não cadastrado em nossos registros!");
    printf("\n\n\t\t\t1 - Cadastrar ID");
    printf("\n\t\t\t2 - Tentar Pesquisa Novamente");
    printf("\n\t\t\t3 - Voltar ao Menu Principal");
    printf("\n\n\t\t\tSelecione uma opção: ");
    scanf("%d", &voltar);
    if (voltar == 1) {
      system("clear");
      cabecalhoPetShop();
      cadastroPetFunction();
    } else if (voltar == 2) {
      system("clear");
      cabecalhoPetShop();
      alterarPet();
    } else {
      system("clear");
      menuPrincipalPetshop();
    }
  } else {
    printf("\t\t\tVoltar ao meu principal? (S:1/N:0): ");
    scanf("%d", &voltar);
    if (voltar == 1) {
      system("clear");
      menuPrincipalPetshop();
    } else {
      exit(1);
    }
  }
}

void listarAnimal() {
  Pet pet;
  int voltar, EOF_ARQ;
  FILE *cadastroPet = fopen("cadastrosPet.bin", "a+b");

  if (cadastroPet == NULL) {
    printf("Erro ao abrir o arquivo!");
    exit(1);
  } else {
    printf("\t\t\t\t\t   PET SHOP BOM PREÇO \n ");
    printf("\t\t\t\t  Seu animal em boas mãos!\n");
    printf("\t\t\t====================================\n");
    printf("\t\t\t||         Lista de animais       ||\n");
    printf("\t\t\t====================================\n");

    while (!feof(cadastroPet)) {
      // Variável para guardar o retorno da função fread
      EOF_ARQ = fread(&pet, sizeof(Pet), 1, cadastroPet);
      if (ferror(cadastroPet)) {
        printf("\n\t\t\tErro na leitura do arquivo");
      } else {
        // Verificar se o retorno de fread não é igual a 0, pois se for nada
        // será impresso
        if (EOF_ARQ != 0) {
          printf("\t\t\tID: %d\n", pet.id);
          printf("\t\t\tNome do Pet: %s", pet.nome);
          printf("\t\t\tNome do Tutor: %s", pet.tutor);
          printf("\t\t\tEndereço: %s", pet.endereco);
          printf("\t\t\tRaça: %s", pet.raca);
          printf("\t\t\tCor: %s", pet.cor);
          printf("\t\t\tTipo: %s", pet.tipo);
          printf("\t\t\tContraindicações: %s", pet.contraindicacoes);
          printf("\t\t\tIdade: %s", pet.idade);
          printf("\n\n");
        }
      }
    }
  }

  fclose(cadastroPet);

  printf("\n\t\t\tVoltar ao meu principal? (S:1/N:0): ");
  scanf("%d", &voltar);
  if (voltar == 1) {
    system("clear");
    menuPrincipalPetshop();
  } else {
    exit(1);
  }
}

void listarAtendimentos() {
  Servico atendimento;
  int voltar, EOF_ARQ;
  FILE *cadastroAtendimento = fopen("cadastroAtendimento.bin", "a+b");

  if (cadastroAtendimento == NULL) {
    printf("Erro ao abrir o arquivo!");
    exit(1);
  } else {
    printf("\n\n");
    printf("\t\t\t\t\t   PET SHOP BOM PREÇO \n ");
    printf("\t\t\t\t  Seu animal em boas mãos!\n");
    printf("\t\t\t====================================\n");
    printf("\t\t\t||      Lista de atendimentos     ||\n");
    printf("\t\t\t====================================\n");

    while (!feof(cadastroAtendimento)) {
      // Variável para guardar o retorno da função fread
      EOF_ARQ = fread(&atendimento, sizeof(Servico), 1, cadastroAtendimento);
      if (ferror(cadastroAtendimento)) {
        printf("\n\t\t\tErro na leitura do arquivo");
      } else {
        // Verificar se o retorno de fread não é igual a 0, pois se for nada
        // será impresso
        if (EOF_ARQ != 0) {
          printf("\t\t\tID: %d\n", atendimento.id);

          switch (atendimento.opcao) {
          case 1:
            printf("\t\t\tServiço: Banho");
            break;
          case 2:
            printf("\t\t\tServiço: Banho e Tosa");
            break;
          case 3:
            printf("\t\t\tServiço: Hidratação");
            break;
          case 4:
            printf("\t\t\tServiço: Desembaraçamento");
            break;
          case 5:
            printf("\t\t\tServiço: Limpeza de ouvido");
            break;
          case 6:
            printf("\t\t\tServiço: Corte de unhas");
            break;
          case 7:
            printf("\t\t\tServiço: Escovação de dentes");
            break;
          default:
            printf("Opção inválida!");
          }
          printf("\n\n");
        }
      }
    }
  }

  fclose(cadastroAtendimento);

  printf("\n\t\t\tVoltar ao meu principal? (S:1/N:0): ");
  scanf("%d", &voltar);
  if (voltar == 1) {
    system("clear");
    menuPrincipalPetshop();
  } else {
    exit(1);
  }
}

void sairPet() {
  system("clear");
  printf("\n\n\n\n\n\n\n\n");
  printf("\t\t\tSessão encerrada!");
  printf("\n\n\n\n\n\n\n\n");
  exit(0);
}

void flush_in() {
  int ch;
  while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
  }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
  int valor;
  struct Lista *proximo;
} Lista;

// Criar uma lista vazia
Lista *criarLista() { return NULL; }

// Inserir um elemento na lista (em ordem crescente)
Lista* inserirLista(Lista* lista, int valor) {
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  if (novo == NULL) {
    printf("Erro ao alocar memória.\n");
    return lista;
  }
  novo->valor = valor;
  novo->proximo = NULL;

  if (lista == NULL || lista->valor > valor) {
    novo->proximo = lista;
    return novo;
  }

  Lista* atual = lista;
  while (atual->proximo != NULL && atual->proximo->valor < valor) {
    atual = atual->proximo;
  }

  novo->proximo = atual->proximo;
  atual->proximo = novo;

  return lista;
}


// Exibir todos os elementos da lista
void exibirLista(Lista *lista) {
  Lista *atual = lista;
  if (atual == NULL) {
    printf("A lista está vazia.\n");
    return;
  }
  while (atual != NULL) {
    printf("%d | ", atual->valor);
    atual = atual->proximo;
  }
  printf("Vazio\n");
}

// Verificar se a lista está vazia
int verificarVazia(Lista *lista) { return lista == NULL; }

// Buscar um elemento da lista
Lista *buscarLista(Lista *lista, int valor) {
  Lista *atual = lista;
  while (atual != NULL) {
    if (atual->valor == valor)
      return atual;
    atual = atual->proximo;
  }
  return NULL;
}

// Excluir um elemento da lista
Lista *excluirLista(Lista *lista, int valor) {
  Lista *atual = lista;
  Lista *anterior = NULL;

  while (atual != NULL && atual->valor != valor) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    printf("Elemento %d não encontrado na lista.\n", valor);
    return lista;
  }

  if (anterior == NULL) {
    lista = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);
  printf("Elemento %d excluído da lista.\n", valor);
  return lista;
}

// Liberar toda a lista
void liberarLista(Lista *lista) {
  Lista *atual = lista;
  while (atual != NULL) {
    Lista *temp = atual;
    atual = atual->proximo;
    free(temp);
  }
  printf("Lista liberada com sucesso.\n");
}

// Código Main
int main() {
  Lista *lista = criarLista();
  int opcao, valor;

  do {
    printf("\n --- Menu de Opções --- \n\n");
    printf("1. Criar/Resetar lista\n");
    printf("2. Inserir elemento\n");
    printf("3. Exibir lista\n");
    printf("4. Verificar se lista está vazia\n");
    printf("5. Buscar elemento\n");
    printf("6. Excluir elemento\n");
    printf("7. Liberar lista\n");
    printf("8. Sair\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
    case 1:
      lista = criarLista();
      printf("Lista criada com sucesso.\n");
      break;
    case 2:
      printf("Digite o valor para inserir: ");
      scanf("%d", &valor);
      lista = inserirLista(lista, valor);
      printf("Elemento %d inserido.\n", valor);
      break;
    case 3:
      printf("Elementos da lista: ");
      exibirLista(lista);
      break;
    case 4:
      if (verificarVazia(lista))
        printf("A lista está vazia.\n");
      else
        printf("A lista não está vazia.\n");
      break;
    case 5:
      printf("Digite o valor para buscar: ");
      scanf("%d", &valor);
      if (buscarLista(lista, valor) != NULL)
        printf("Valor %d encontrado na lista.\n", valor);
      else
        printf("Valor %d não encontrado na lista.\n", valor);
      break;
    case 6:
      printf("Digite o valor para excluir: ");
      scanf("%d", &valor);
      lista = excluirLista(lista, valor);
      break;
    case 7:
      liberarLista(lista);
      lista = NULL;
      break;
    case 8:
      printf("Saindo...\n");
      liberarLista(lista);
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  } while (opcao != 8);

  return 0;
}

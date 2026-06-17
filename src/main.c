#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* Inserir(struct ListNode* head, int val) {

    struct ListNode* novo = malloc(sizeof(struct ListNode));
    novo->val = val;
    novo->next = NULL;

    if(head == NULL)
        return novo;

    struct ListNode* aux = head;

    while(aux->next)
        aux = aux->next;

    aux->next = novo;

    return head;
}

int tamanhoLista(struct ListNode* head) {
    int tam = 0;
    struct ListNode* aux = head;
    while(aux) {
        aux = aux->next;
        tam++;
    }
    return tam;
}

void vetorLista(struct ListNode* head, int vet[]) {
    int i = 0;
    struct ListNode* aux = head;
    while(aux) {
        vet[i] = aux->val;
        i++;
        aux = aux->next;
    }
}

struct TreeNode* MontarBST(int vet[], int inicio, int fim) {
    if(inicio > fim) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int meio = inicio + (fim - inicio) / 2;
    root->val = vet[meio];
    root->left = MontarBST(vet, inicio, meio-1);
    root->right = MontarBST(vet, meio+1, fim);
    return root;
}
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int tam = tamanhoLista(head);
    int* vet = (int*)malloc(sizeof(int) * tam);
    vetorLista(head, vet);
    struct TreeNode* root = MontarBST(vet, 0, tam - 1);
    return root;
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int main() {
    struct ListNode *head = NULL;
    head = Inserir(head, 1);
    head = Inserir(head, 2);
    head = Inserir(head, 3);
    head = Inserir(head, 4);
    head = Inserir(head, 5);
    head = Inserir(head, 6);
    Imprimir(sortedListToBST(head));
    return 0;
}

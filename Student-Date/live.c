#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char  nrp[20];
    char  nama[50];
    float ipk;
} DataMahasiswa;

typedef struct Node {
    DataMahasiswa data;
    struct Node  *next;
} Node;

Node *head = NULL;

void insertAkhir(char *nrp, char *nama, float ipk) {
    Node *baru = (Node *)malloc(sizeof(Node));
    strcpy(baru->data.nrp, nrp);
    strcpy(baru->data.nama, nama);
    baru->data.ipk = ipk;
    baru->next = NULL;

    if (!head) { head = baru; return; }
    Node *curr = head;
    while (curr->next) curr = curr->next;
    curr->next = baru;
}

void cetakHeader() {
    printf("%-15s %-20s %-6s\n", "NRP", "Nama", "IPK");
    printf("%-15s %-20s %-6s\n", "--------------", "-------------------", "-----");
}

void tampilNormal() {
    printf("\nData Mahasiswa :\n");
    cetakHeader();
    Node *curr = head;
    while (curr) {
        printf("%-15s %-20s %.2f\n", curr->data.nrp, curr->data.nama, curr->data.ipk);
        curr = curr->next;
    }
    printf("\n");
}

void tampilByIPK() {
    int n = 0;
    Node *curr = head;
    while (curr) { n++; curr = curr->next; }

    Node **arr = (Node **)malloc(n * sizeof(Node *));
    curr = head;
    for (int i = 0; i < n; i++) { 
        arr[i] = curr;
        curr = curr->next;
        }

    // Bubble sort descending
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j]->data.ipk < arr[j+1]->data.ipk) {
                Node *tmp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = tmp;
            }

    printf("\nData Mahasiswa (IPK Tertinggi) :\n");
    cetakHeader();
    for (int i = 0; i < n; i++)
        printf("%-15s %-20s %.2f\n", arr[i]->data.nrp, arr[i]->data.nama, arr[i]->data.ipk);
    printf("\n");
    free(arr);
}

int main() {
    int pilihan;
    char nrp[20], nama[50];
    float ipk;

    do {
        printf("=== MENU DATA MAHASISWA ===\n");
        printf("1. Insert Data\n");
        printf("2. Tampilkan Data\n");
        printf("3. Tampilkan IPK Tertinggi\n");
        printf("4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan) {
            case 1:
                printf("NRP  : "); scanf("%s", nrp);
                printf("Nama : "); scanf(" %[^\n]", nama);
                printf("IPK  : "); scanf("%f", &ipk);
                insertAkhir(nrp, nama, ipk);
                printf("Data berhasil ditambahkan!\n\n");
                break;
            case 2: tampilNormal();  break;
            case 3: tampilByIPK();   break;
            case 4: printf("Keluar.\n"); break;
            default: printf("Pilihan tidak valid!\n\n");
        }
    } while (pilihan != 4);

    return 0;
}
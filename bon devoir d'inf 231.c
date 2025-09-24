#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Définition d'une constante pour la taille maximale

// ===================== FONCTIONS DE MATRICES =====================

// 1. Somme de matrices
void sommeMatrices(int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez les elements de la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez les elements de la matrice B (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Somme des matrices :\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// 2. Produit de matrices
void produitMatrices(int n, int m, int p) {
    if(n > MAX || m > MAX || p > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez la matrice B (%dx%d):\n", m, p);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;
            for(int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Produit des matrices (%dx%d):\n", n, p);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// ===================== FONCTIONS SUR TABLEAU =====================

// 3. Recherche séquentielle
int rechercheSeq(int T[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(T[i] == x) return i; 
    }
    return -1;
}

// 4. Multiplication avec uniquement +1
int produitAvecPlus(int a, int b) {
    if(a < 0 || b < 0) {
        printf("Erreur : a et b doivent etre >= 0\n");
        return -1;
    }
    
    int res = 0;
    for(int i = 0; i < b; i++) 
        res = res + a;
    return res;
}

// 5. Tester si un tableau est trié
int estTrie(int T[], int n) {
    if(n <= 1) return 1; // Tableau vide ou à 1 élément est considéré trié
    
    for(int i = 0; i < n - 1; i++) {
        if(T[i] > T[i + 1]) return 0;
    }
    return 1;
}

// 6. Médiane dans un tableau
void mediane(int T[], int n) {
    if(n > MAX) {
        printf("Erreur : tableau trop grand\n");
        return;
    }
    
    // Tri par sélection
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(T[j] < T[min]) min = j;
        int tmp = T[i]; 
        T[i] = T[min]; 
        T[min] = tmp;
    }

    if(n % 2 == 1)
        printf("Mediane = %d\n", T[n / 2]);
    else
        printf("Mediane = %.2f\n", ((double)T[n / 2 - 1] + T[n / 2]) / 2);
}

// 7. Inverser un tableau
void inverser(int T[], int n) {
    for(int i = 0; i < n / 2; i++) {
        int tmp = T[i]; 
        T[i] = T[n - 1 - i]; 
        T[n - 1 - i] = tmp;
    }
    printf("Tableau inverse : ");
    for(int i = 0; i < n; i++) 
        printf("%d ", T[i]);
    printf("\n");
}

// ===================== PRODUITS VECTEURS =====================

// 8. Produit vectoriel (3D uniquement)
void produitVectoriel(int u[3], int v[3], int res[3]) {
    res[0] = u[1] * v[2] - u[2] * v[1];
    res[1] = u[2] * v[0] - u[0] * v[2];
    res[2] = u[0] * v[1] - u[1] * v[0];
}

// 9. Produit vecteur × matrice
void vecteurMatrice(int v[], int A[MAX][MAX], int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes\n");
        return;
    }
    
    int res[MAX];
    for(int j = 0; j < m; j++) {
        res[j] = 0;
        for(int i = 0; i < n; i++)
            res[j] += v[i] * A[i][j];
    }

    printf("Resultat du vecteur x matrice : ");
    for(int j = 0; j < m; j++) 
        printf("%d ", res[j]);
    printf("\n");
}

// ===================== PROGRAMME PRINCIPAL =====================

int main() {
    int choix;
    
    printf("=== PROGRAMME DE CALCULS MATRICIELS ET VECTORIELS ===\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle\n");
        printf("4. Produit a*b avec +1 uniquement\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Mediane dans un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur x matrice\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                int n, m;
                printf("Dimensions n m : ");
                scanf("%d%d", &n, &m);
                sommeMatrices(n, m);
                break;
            }
            case 2: {
                int n, m, p;
                printf("Dimensions (n x m) * (m x p) : ");
                scanf("%d%d%d", &n, &m, &p);
                produitMatrices(n, m, p);
                break;
            }
            case 3: {
                int n, x, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                printf("Element a chercher : ");
                scanf("%d", &x);
                int pos = rechercheSeq(T, n, x);
                if(pos == -1) 
                    printf("Element non trouve\n");
                else 
                    printf("Element trouve a la position %d\n", pos + 1); // correction
                break;
            }
            case 4: {
                int a, b;
                printf("Entrez a et b (>=0): ");
                scanf("%d%d", &a, &b);
                int resultat = produitAvecPlus(a, b);
                if(resultat != -1)
                    printf("Produit = %d\n", resultat);
                break;
            }
            case 5: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                if(estTrie(T, n)) 
                    printf("Le tableau est trie\n");
                else 
                    printf("Le tableau n'est pas trie\n");
                break;
            }
            case 6: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                mediane(T, n);
                break;
            }
            case 7: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                inverser(T, n);
                break;
            }
            case 8: {
                int u[3], v[3], res[3];
                printf("Entrez vecteur u (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &u[i]);
                printf("Entrez vecteur v (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &v[i]);
                produitVectoriel(u, v, res);
                printf("Produit vectoriel = (%d, %d, %d)\n", res[0], res[1], res[2]);
                break;
            }
            case 9: {
                int n, m, v[MAX], A[MAX][MAX];
                printf("Taille du vecteur : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez vecteur (%d): ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &v[i]);
                printf("Dimensions matrice (%dxm): m = ", n);
                scanf("%d", &m);
                if(m > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez matrice (%dx%d):\n", n, m);
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        scanf("%d", &A[i][j]);
                vecteurMatrice(v, A, n, m);
                break;
            }
            case 0:#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Définition d'une constante pour la taille maximale

// ===================== FONCTIONS DE MATRICES =====================

// 1. Somme de matrices
void sommeMatrices(int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez les elements de la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez les elements de la matrice B (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Somme des matrices :\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// 2. Produit de matrices
void produitMatrices(int n, int m, int p) {
    if(n > MAX || m > MAX || p > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez la matrice B (%dx%d):\n", m, p);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;
            for(int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Produit des matrices (%dx%d):\n", n, p);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// ===================== FONCTIONS SUR TABLEAU =====================

// 3. Recherche séquentielle
int rechercheSeq(int T[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(T[i] == x) return i; 
    }
    return -1;
}

// 4. Multiplication avec uniquement +1
int produitAvecPlus(int a, int b) {
    if(a < 0 || b < 0) {
        printf("Erreur : a et b doivent etre >= 0\n");
        return -1;
    }
    
    int res = 0;
    for(int i = 0; i < b; i++) 
        res = res + a;
    return res;
}

// 5. Tester si un tableau est trié
int estTrie(int T[], int n) {
    if(n <= 1) return 1; // Tableau vide ou à 1 élément est considéré trié
    
    for(int i = 0; i < n - 1; i++) {
        if(T[i] > T[i + 1]) return 0;
    }
    return 1;
}

// 6. Médiane dans un tableau
void mediane(int T[], int n) {
    if(n > MAX) {
        printf("Erreur : tableau trop grand\n");
        return;
    }
    
    // Tri par sélection
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(T[j] < T[min]) min = j;
        int tmp = T[i]; 
        T[i] = T[min]; 
        T[min] = tmp;
    }

    if(n % 2 == 1)
        printf("Mediane = %d\n", T[n / 2]);
    else
        printf("Mediane = %.2f\n", ((double)T[n / 2 - 1] + T[n / 2]) / 2);
}

// 7. Inverser un tableau
void inverser(int T[], int n) {
    for(int i = 0; i < n / 2; i++) {
        int tmp = T[i]; 
        T[i] = T[n - 1 - i]; 
        T[n - 1 - i] = tmp;
    }
    printf("Tableau inverse : ");
    for(int i = 0; i < n; i++) 
        printf("%d ", T[i]);
    printf("\n");
}

// ===================== PRODUITS VECTEURS =====================

// 8. Produit vectoriel (3D uniquement)
void produitVectoriel(int u[3], int v[3], int res[3]) {
    res[0] = u[1] * v[2] - u[2] * v[1];
    res[1] = u[2] * v[0] - u[0] * v[2];
    res[2] = u[0] * v[1] - u[1] * v[0];
}

// 9. Produit vecteur × matrice
void vecteurMatrice(int v[], int A[MAX][MAX], int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes\n");
        return;
    }
    
    int res[MAX];
    for(int j = 0; j < m; j++) {
        res[j] = 0;
        for(int i = 0; i < n; i++)
            res[j] += v[i] * A[i][j];
    }

    printf("Resultat du vecteur x matrice : ");
    for(int j = 0; j < m; j++) 
        printf("%d ", res[j]);
    printf("\n");
}

// ===================== PROGRAMME PRINCIPAL =====================

int main() {
    int choix;
    
    printf("=== PROGRAMME DE CALCULS MATRICIELS ET VECTORIELS ===\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle\n");
        printf("4. Produit a*b avec +1 uniquement\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Mediane dans un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur x matrice\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                int n, m;
                printf("Dimensions n m : ");
                scanf("%d%d", &n, &m);
                sommeMatrices(n, m);
                break;
            }
            case 2: {
                int n, m, p;
                printf("Dimensions (n x m) * (m x p) : ");
                scanf("%d%d%d", &n, &m, &p);
                produitMatrices(n, m, p);
                break;
            }
            case 3: {
                int n, x, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                printf("Element a chercher : ");
                scanf("%d", &x);
                int pos = rechercheSeq(T, n, x);
                if(pos == -1) 
                    printf("Element non trouve\n");
                else 
                    printf("Element trouve a la position %d\n", pos + 1); // correction
                break;
            }
            case 4: {
                int a, b;
                printf("Entrez a et b (>=0): ");
                scanf("%d%d", &a, &b);
                int resultat = produitAvecPlus(a, b);
                if(resultat != -1)
                    printf("Produit = %d\n", resultat);
                break;
            }
            case 5: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                if(estTrie(T, n)) 
                    printf("Le tableau est trie\n");
                else 
                    printf("Le tableau n'est pas trie\n");
                break;
            }
            case 6: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                mediane(T, n);
                break;
            }
            case 7: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                inverser(T, n);
                break;
            }
            case 8: {
                int u[3], v[3], res[3];
                printf("Entrez vecteur u (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &u[i]);
                printf("Entrez vecteur v (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &v[i]);
                produitVectoriel(u, v, res);
                printf("Produit vectoriel = (%d, %d, %d)\n", res[0], res[1], res[2]);
                break;
            }
            case 9: {
                int n, m, v[MAX], A[MAX][MAX];
                printf("Taille du vecteur : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez vecteur (%d): ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &v[i]);
                printf("Dimensions matrice (%dxm): m = ", n);
                scanf("%d", &m);
                if(m > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez matrice (%dx%d):\n", n, m);
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        scanf("%d", &A[i][j]);
                vecteurMatrice(v, A, n, m);
                break;
            }
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while(choix != 0);

    return 0;
}#include <stdio.h>
#include <stdlib.h>

#define MAX 50  // Définition d'une constante pour la taille maximale

// ===================== FONCTIONS DE MATRICES =====================

// 1. Somme de matrices
void sommeMatrices(int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez les elements de la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez les elements de la matrice B (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Somme des matrices :\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// 2. Produit de matrices
void produitMatrices(int n, int m, int p) {
    if(n > MAX || m > MAX || p > MAX) {
        printf("Erreur : dimensions trop grandes (max %d)\n", MAX);
        return;
    }
    
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Entrez la matrice A (%dx%d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    
    printf("Entrez la matrice B (%dx%d):\n", m, p);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++) {
            C[i][j] = 0;
            for(int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Produit des matrices (%dx%d):\n", n, p);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
}

// ===================== FONCTIONS SUR TABLEAU =====================

// 3. Recherche séquentielle
int rechercheSeq(int T[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(T[i] == x) return i; 
    }
    return -1;
}

// 4. Multiplication avec uniquement +1
int produitAvecPlus(int a, int b) {
    if(a < 0 || b < 0) {
        printf("Erreur : a et b doivent etre >= 0\n");
        return -1;
    }
    
    int res = 0;
    for(int i = 0; i < b; i++) 
        res = res + a;
    return res;
}

// 5. Tester si un tableau est trié
int estTrie(int T[], int n) {
    if(n <= 1) return 1; // Tableau vide ou à 1 élément est considéré trié
    
    for(int i = 0; i < n - 1; i++) {
        if(T[i] > T[i + 1]) return 0;
    }
    return 1;
}

// 6. Médiane dans un tableau
void mediane(int T[], int n) {
    if(n > MAX) {
        printf("Erreur : tableau trop grand\n");
        return;
    }
    
    // Tri par sélection
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(T[j] < T[min]) min = j;
        int tmp = T[i]; 
        T[i] = T[min]; 
        T[min] = tmp;
    }

    if(n % 2 == 1)
        printf("Mediane = %d\n", T[n / 2]);
    else
        printf("Mediane = %.2f\n", ((double)T[n / 2 - 1] + T[n / 2]) / 2);
}

// 7. Inverser un tableau
void inverser(int T[], int n) {
    for(int i = 0; i < n / 2; i++) {
        int tmp = T[i]; 
        T[i] = T[n - 1 - i]; 
        T[n - 1 - i] = tmp;
    }
    printf("Tableau inverse : ");
    for(int i = 0; i < n; i++) 
        printf("%d ", T[i]);
    printf("\n");
}

// ===================== PRODUITS VECTEURS =====================

// 8. Produit vectoriel (3D uniquement)
void produitVectoriel(int u[3], int v[3], int res[3]) {
    res[0] = u[1] * v[2] - u[2] * v[1];
    res[1] = u[2] * v[0] - u[0] * v[2];
    res[2] = u[0] * v[1] - u[1] * v[0];
}

// 9. Produit vecteur × matrice
void vecteurMatrice(int v[], int A[MAX][MAX], int n, int m) {
    if(n > MAX || m > MAX) {
        printf("Erreur : dimensions trop grandes\n");
        return;
    }
    
    int res[MAX];
    for(int j = 0; j < m; j++) {
        res[j] = 0;
        for(int i = 0; i < n; i++)
            res[j] += v[i] * A[i][j];
    }

    printf("Resultat du vecteur x matrice : ");
    for(int j = 0; j < m; j++) 
        printf("%d ", res[j]);
    printf("\n");
}

// ===================== PROGRAMME PRINCIPAL =====================

int main() {
    int choix;
    
    printf("=== PROGRAMME DE CALCULS MATRICIELS ET VECTORIELS ===\n");
    
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle\n");
        printf("4. Produit a*b avec +1 uniquement\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Mediane dans un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel (3D)\n");
        printf("9. Produit vecteur x matrice\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: {
                int n, m;
                printf("Dimensions n m : ");
                scanf("%d%d", &n, &m);
                sommeMatrices(n, m);
                break;
            }
            case 2: {
                int n, m, p;
                printf("Dimensions (n x m) * (m x p) : ");
                scanf("%d%d%d", &n, &m, &p);
                produitMatrices(n, m, p);
                break;
            }
            case 3: {
                int n, x, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                printf("Element a chercher : ");
                scanf("%d", &x);
                int pos = rechercheSeq(T, n, x);
                if(pos == -1) 
                    printf("Element non trouve\n");
                else 
                    printf("Element trouve a la position %d\n", pos + 1); // correction
                break;
            }
            case 4: {
                int a, b;
                printf("Entrez a et b (>=0): ");
                scanf("%d%d", &a, &b);
                int resultat = produitAvecPlus(a, b);
                if(resultat != -1)
                    printf("Produit = %d\n", resultat);
                break;
            }
            case 5: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                if(estTrie(T, n)) 
                    printf("Le tableau est trie\n");
                else 
                    printf("Le tableau n'est pas trie\n");
                break;
            }
            case 6: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                mediane(T, n);
                break;
            }
            case 7: {
                int n, T[MAX];
                printf("Taille du tableau : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez les %d elements : ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &T[i]);
                inverser(T, n);
                break;
            }
            case 8: {
                int u[3], v[3], res[3];
                printf("Entrez vecteur u (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &u[i]);
                printf("Entrez vecteur v (3D): ");
                for(int i = 0; i < 3; i++) 
                    scanf("%d", &v[i]);
                produitVectoriel(u, v, res);
                printf("Produit vectoriel = (%d, %d, %d)\n", res[0], res[1], res[2]);
                break;
            }
            case 9: {
                int n, m, v[MAX], A[MAX][MAX];
                printf("Taille du vecteur : ");
                scanf("%d", &n);
                if(n > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez vecteur (%d): ", n);
                for(int i = 0; i < n; i++) 
                    scanf("%d", &v[i]);
                printf("Dimensions matrice (%dxm): m = ", n);
                scanf("%d", &m);
                if(m > MAX) {
                    printf("Erreur : taille maximale depassee (%d)\n", MAX);
                    break;
                }
                printf("Entrez matrice (%dx%d):\n", n, m);
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < m; j++)
                        scanf("%d", &A[i][j]);
                vecteurMatrice(v, A, n, m);
                break;
            }
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while(choix != 0);

    return 0;
}
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide !\n");
        }
    } while(choix != 0);

    return 0;
}
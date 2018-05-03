typedef struct fila *Fila;

Fila Inicializar();

Fila Destruir(Fila f);

int vazia(Fila f);

int cheia(Fila f);

void Inserir(Fila f, int x);

int remover(Fila f);

void imprimir(Fila f);

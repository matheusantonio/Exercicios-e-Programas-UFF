import pandas as pd 
import matplotlib.pyplot as plt

arqNome=input("Digite o nome do arquivo lida")

df = pd.read_csv('tabelas\\' + arqNome + '.csv', index_col='Valor Binario').sort_index()
df.plot(figsize=(15, 5), title='Quantidade de bits')
plt.savefig('plots\\' + arqNome + '.png')
    
print("Arquivos gerados com sucesso!")
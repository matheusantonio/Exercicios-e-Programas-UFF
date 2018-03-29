import pandas as pd 
import matplotlib.pyplot as plt

print("Insira o nome do arquivo usado no programa em C")
imgNome = input()

df = pd.read_csv('tabelas\\' + imgNome + '.csv', index_col='bit').sort_index()
df.plot(figsize=(15, 5), title='Quantidade de bits')
plt.savefig('plots\\' + imgNome + '.png')

print("Arquivos gerados com sucesso!")
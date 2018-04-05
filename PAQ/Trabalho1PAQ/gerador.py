import pandas as pd 
import matplotlib.pyplot as plt

imgNome=input("Digite o nome da imagem lida")

df = pd.read_csv('tabelas\\' + imgNome + '.csv', index_col='bit').sort_index()
df.plot(figsize=(15, 5), title='Quantidade de bits')
plt.savefig('plots\\' + imgNome + '.png')
    
print("Arquivos gerados com sucesso!")
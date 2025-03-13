# Classificação de Pacientes com Base em Indicadores de Saúde 🩺💊
Nos hospitais modernos, a análise eficiente de dados clínicos é essencial para apoiar decisões médicas. Médicos e pesquisadores frequentemente lidam com grandes volumes de informações provenientes de exames laboratoriais e sintomas relatados pelos pacientes. Um desafio importante é identificar padrões nesses dados para prever o estado de saúde dos indivíduos e auxiliar no diagnóstico precoce de doenças. Considerando a crescente demanda, um hospital universitário deseja desenvolver um sistema de suporte à decisão baseado em aprendizado de máquina para auxiliar médicos na classificação de pacientes entre saudáveis e doentes. Para isso, foi construída uma tabela (com números do tipo float) contendo o histórico de pacientes atendidos no hospital, onde cada linha representa um paciente e cada coluna representa um indicador clínico (por exemplo: pressão arterial, nível de glicose no sangue, frequência cardíaca, entre outros).


<img src ="https://amurel.org.br/uploads/sites/16/2022/10/3122700.png">

A última coluna da tabela é especial e contém a classificação do paciente, sendo:
* <b>1.0</b> se o paciente foi considerado saudável 🙂
*  <b>-1.0</b> se o paciente foi diagnosticado com alguma condição de saúde preocupante (doente) 🤢

	<table border="2" >
	<tr>
	<td> 0,2</td>
	<td>0,5</td>
	<td> 0,2 </td>
	<td> <b> 1.0 </b></td>
	</tr>
	<tr>
	<td>0,5</td>
	<td>2,0</td>
	<td> 0,2</td>
	<td> <b>-1,0</b></td>
	</tr>
	</table>

 
<hr>
Com base nesses dados, deseja-se desenvolver um modelo capaz de classificar um novo paciente de forma automática, reduzindo o tempo necessário para um diagnóstico inicial e auxiliando na triagem médica.

Exemplo

<table border="2" >
<tr>
<td> 0,2</td>
<td>0,5</td>
<td> 0,2 </td>
<td> <b> 1.0 </b></td>
</tr>
<tr>
<td>0,5</td>
<td>2,0</td>
<td> 0,2</td>
<td> <b>-1,0</b></td>
</tr>
<tr>
<td>0,5</td>
<td>0,3</td>
<td>0,2</td>
<td><b>???</b></td>
</tr>
</table>	
<h2>Objetivo</h2>
Esta aplicação determina a probabilidade de um novo paciente estar doente ou saudável, comparando seus indicadores (sintomas e exames) com um histórico de pacientes, utilizando a distância euclidiana.

## Funcionamento

### Preenchimento da Tabela

-   Foi utilizada uma matriz de floats alocada estaticamente.
    
-   Dimensões:
    
    -   11 linhas (10 pacientes + 1 paciente novo).
        
    -   Entre 3 e 7 colunas (indicadores de sintomas/exames).
        
    -   A última coluna indica a condição do paciente: **1.0 (saudável)** ou **-1.0 (doente)**.
        
-   Caso os valores de dimensão não atendessem aos requisitos, o programa solicitava novos valores.
    

### Cálculo da Distância

-   Foi utilizada a **distância euclidiana** entre o paciente novo e os pacientes históricos.
    <img src="https://miro.medium.com/v2/resize:fit:984/1*P3BtScK5X3v-0-O-joFJFQ.png">

### Classificação do Novo Paciente

-   Se o paciente histórico mais próximo fosse **saudável**, o paciente novo tinha mais chance de ser saudável.
    
-   Se o paciente histórico mais próximo fosse **doente**, o paciente novo tinha mais chance de estar doente.
    
-   A tabela completa era exibida ao final da classificação.
    


-   **Tecnologias utilizadas**
    
    -   Linguagem: **C++**
    -   Bibliotecas padrão utilizadas: `<iostream>`, `<cmath>`, `<cstdlib>`, `<ctime>`
-   **Funcionalidades**
    
    -   **Validação de entrada**: Garante que o usuário insira valores corretos.
    -   **Cálculo automático da classificação**: O programa analisa a distância euclidiana e classifica o novo paciente automaticamente.
    -   **Exibição formatada da tabela** no terminal para melhor visualização.
-   **Possíveis melhorias futuras**
    
    -   Implementação de uma opção para **preenchimento automático** da matriz com valores randômicos (útil para testes).
    -   Exportação dos dados para um **arquivo CSV** para análise posterior.
-   **Como executar o código**
    

    
			 g++ IndicadorSaude.cpp -o IndicadorSaude.exe
			 ./"IndicadorSaude.exe"
    
   
  


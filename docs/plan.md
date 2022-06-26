
Módulo de Servidores -> Responsável: Raquel Maciel Coelho de Sousa
- função para inserir um novo servidor 
- função para alterar um servidor existente 
- função para excluir um servidor 
- função para mostrar/imprimir dados de um servidor com base no código 
- função para mostrar/imprimir todos os servidores 
- função para mostrar/imprimir todos os servidores em ordem alfabética pelo nome
- função para mostrar/imprimir todos os professores(servidores) em ordem alfabética pelo nome  - função mostrar/imprimir todos os técnicos administrativos em ordem alfabética pelo nome 
- função para verificar a unicidade do código do servidor
- função para verificar a unicidade do CPF do servidor
- função para verificar a unicidade do SIAPE do servidor
- função para checar campos obrigatórios
- funções de tratamento de dados vindos do usuário
- função geradora de códigos de identificação de servidor

Módulo de Veículos  -> Responsável: Vinícius Menezes Monte
- função para inserir uma nova veículo 
- função para alterar uma veículo existente 
- função para excluir uma veículo 
- função para mostrar/imprimir dados de uma veículo com base no código 
- função para mostrar/imprimir todas as veículos de um servidor 
- função para mostrar/imprimir todas as veículos de um servidor em ordem alfabética pelo nome  
- função para verificar a unicidade do código do veículo
- função verificadora de existência do servidor
- função verificadora de unicidade da descrição do veículo
- função para checar campos obrigatórios
- funções de tratamento de dados vindos do usuário
- função geradora de códigos de identificação de veículo


Atividades Complementares -> Responsável: Ambos
- Redigir headers dos módulos
- Implementar o arquivo principal, que usa as funções implementadas nos arquivos em um arquivo principal (main.c) que  contém a função main()
- Fazer perfumaria



Planejamento UI:
Tela inicial:
    Espero ele entrar com enter pra continuar
    -> padronizar nome das funcoes do codigo
    -> mostrar opção escolhida e pedir confirmação
    fazer operacao
    -> feedback de sucesso ou nao
    
Inserir dados:
    -> Boto labelzinho de obrigatoriedade 
    -> Feedback de entrada errada
    -> Exemplo do que inserir
    **Após a criação eu devo dar um feedback e um resumo das informações dadas e inseridas no banco?
    -> Feedback de sucesso ou não
    -> Mostro dados inseridos e codigo que eu criei pra pessoa

Editar:
    -> checar se o codigo repetido não é o meu proprio *cries 
    -> checar se existe pra editar
    
    -> mostrar como o campo ta atualmente: 

    -> Descrição:
    -> Descricao antiga exemplo (ai se n quiser editar so da enter)


Ler:
    -> se n tiver nenhum avisa q n tem
    -> foram achados n registros

Ler em ordem alfabética:
    -> mostrar o modo que ta

Deletar:
    opção de cancelar operação no inicio ou toda hr?
    -> qual identificação do item deletado (cpf, placa)
    -> mostrar se existia algo antes

Escolher servidor existente:
    -> entra com cpf, ve e informa se existe ou nao



Chat:

    Sim
    meudeus muito ruim não ter direito o que seguir
    até li o livro que ele indicou mas ainda assim não contém tudo que ele ensina
    os modos que prefere que o codigo seja feito ele so fala na aula ao vivo






PseudoCodigo Fluxo CRUD:
 
Criar:
    pedir campos da struct
    checar uniquidade do campo inserido
    iterar arquivo e ve se há espaço vazio
    se não existir
        append struct no file
    se existir
        sobrescreve naquela posicao livre

Editar:
    pegar struct por codigo
    se nao existir 
        retorna false
    printa struct
    perguntar campo a campo se va querer editar ou não
    se quiser
        edita campo 
        se for campo unico
            checar uniquidade do campo inserido
    sobrescreve struct alterada no arquivo na posicao achada

Excluir:
    pegar struct por codigo
    se nao existir 
        retorna false
    setar flag ocupada pra 0
    printa struct
    sobrescreve struct alterada no arquivo na posicao achada
    retorna true

Ler por código:
    pegar struct por codigo
    se nao existir 
        retorna false
    printa struct
    retorna true

Ler todos:
    se não existir registro
        avisa na tela
    itera arquivo inteiro
    pega struct na posicao
    printa struct
    retorna true;

Ler todos em ordem alfabetica(filtro):
    itera arquivo inteiro
    pega struct na posicao
    tranforma em tupla com o campo a ser ordenado (nome/descricao)
    ordena tuplas
    itera tuplas 
        pega struct na posicao da tupla
        filtro não existir || filtro for satisfeito
            printa struct na posicao do tupla
    fechar arquivo


Pegar position struct por campo escolhido
    pedir codigo do objeto
    itera arquivo
        se achar
            fecha arquivo
            retorna posicao
    fecha arquivo
    retorna -1

Printar struct na posicao:
    abrir arquivo na posicao
    printstruct
    fecha arquivo


Achar posicao livre nas structs do arquivo:
    pegar posicao struct por campo is free
    se posicao == -1
        return false
    return true

Append no arquivo:
    abre arquivo pra append
    escreve struct
    fecha

Sobrescreve arquivo na posicao:
    abre arquivo na posicao
    escreve struct
    fecha

Checar uniquidade:
    pegar posicao struct por campo inserido
    se posicao != -1 e != posicao_a_ignorar
        return false
    return true

---

TODO:
Implementar cascade delete
Ao deletar um servidor, deletar todos os veículos que ele tenha.

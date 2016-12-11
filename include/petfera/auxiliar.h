/**
  * @file 		auxiliar.h
  * @brief 		Funções auxiliares 
  * @details 	Declaração de funções auxiliares
  * @author		David Cardoso
  * @since		31/10/2016
  * @date		10/11/2016
  * @copyright 	2016 - All rights reserveds
  * @sa 		http://projetos.imd.ufrn.br/davidcardoso-ti/imd0030-projeto2/blob/master/include/petfera/auxiliar.h
  */

#ifndef AUX_H
#define AUX_H
#pragma once

#include <iostream>     // biblioteca de entrada e saída do C++
#include <fstream>    	// biblioteca de manipulação de arquivos do C++
#include <string>     	// biblioteca string do C++
#include <map>     		// biblioteca STL de dicionario do C++
#include <vector>     	// biblioteca STL de vetor do C++
#include <algorithm>    // biblioteca de algoritmos do C++
#include "../../include/petfera/pessoa_tratador.h"			// tratador
#include "../../include/petfera/pessoa_veterinario.h"		// veterinario
#include "../../include/petfera/classe_anfibio_nativo.h" 	// anfibio nativo
#include "../../include/petfera/classe_anfibio_exotico.h"	// anfibio exotico
#include "../../include/petfera/classe_ave_nativo.h" 		// ave nativo
#include "../../include/petfera/classe_ave_exotico.h" 		// ave exotico
#include "../../include/petfera/classe_mamifero_nativo.h" 	// mamifero nativo
#include "../../include/petfera/classe_mamifero_exotico.h"	// mamifero exotico
#include "../../include/petfera/classe_reptil_nativo.h" 	// reptil nativo
#include "../../include/petfera/classe_reptil_exotico.h" 	// reptil exotico

using namespace std;

/**
 * limpar entrada padrão "cin"
 */
void clearEntrada(void);

/**
 * preenche dicionario de objeto Pessoa com conteudo do arquivo
 * @param  pessoas      - referencia para a dicionario
 * @param  path_pessoas - caminho do arquivo
 * @param  pessoas_last_id - ultimo ID de pessoa
 * @return boolean
 */
bool fillPessoas(map<int, Pessoa*> &pessoas, string path_pessoas, int &pessoas_last_id);

/**
 * preenche dicionario de objeto Animal com conteudo do arquivo
 * @param  pessoas      - referencia para a dicionario
 * @param  animais      - referencia para a dicionario
 * @param  path_animais - caminho do arquivo
 * @param  animais_last_id - ultimo ID de animal
 * @return boolean
 */
bool fillAnimais(map<int, Pessoa*> &pessoas, map<int, Animal*> &animais, string path_animais, int &animais_last_id);

/**
 * função explode()
 * @details 	quebra uma string de acordo com um caracter separador
 * @param 		s - string
 * @param 		c - caracter
 * @return 		vetor contendo as partes da string
 */
const vector<string> explode(const string s, const char c);

/**
 * salvar dados das dicionarios de objetos Pessoa e Animal em arquivos
 * @param 	dicionario_pessoas - dicionario de ponteiro para objeto Pessoa
 * @param 	dicionario_animais - dicionario de ponteiro para objeto Animal
 * @param 	path_pessoas - caminho do arquivo pessoa
 * @param 	path_animais - caminho do arquivo animal
 * @return 	boolean
 */
bool saveInFiles(map<int, Pessoa*> dicionario_pessoas, map<int, Animal*> dicionario_animais, string path_pessoas, string path_animais);

/**
 * pesquisar uma pessoa pelo ID
 * @param dicionario_pessoas
 * @return iterador para dicionario de pessoas
 */
map<int, Pessoa*>::iterator searchPessoa(map<int, Pessoa*> &dicionario_pessoas);

/**
 * pesquisar um animal pelo ID
 * @param dicionario_animais
 * @param all_options - se true, mostra todas as opções
 * @return iterador para dicionario de animais
 */
map<int, Animal*>::iterator searchAnimal(map<int, Animal*> &dicionario_animais, bool all_options = true);

/**
 * cadastro rápido de um novo animal (id, classe e batismo)
 * @param  animais - dicionario de animais
 * @param  animais_last_id - ultimo ID animal
 * @return boolean
 */
bool newQuickAnimal(map<int, Animal*> &animais, int &animais_last_id);

/**
 * cadastro de novo funcionário
 * @param  	dicionario_pessoas 
 * @param  	pessoas_last_id 
 * @return 	boolean
 */
bool newFuncionario(map<int, Pessoa*> &dicionario_pessoas, int &pessoas_last_id);

/**
 * excluir funcionário pelo ID
 * @param dicionario_pessoas
 * @param dicionario_animais
 */
void delPessoa(map<int, Pessoa*> &dicionario_pessoas, map<int, Animal*> &dicionario_animais);

/**
 * excluir animal pelo ID
 * @param dicionario_animais
 */
void delAnimal(map<int, Animal*> &dicionario_animais);

/**
 * Imprimir menu de opçoes para o usuário
 */
void printMenu(void);

#endif // AUX_H
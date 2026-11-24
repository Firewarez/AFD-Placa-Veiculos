// Automato finito determinístico (AFD) para validar placas de veículos
// Lib MAP usada para armazenar a função de transição do autômato
// Lib Utility usada para armazenar o par de estado e caractere como chave do map

#include <iostream>
#include <map>
#include <utility>

int main() {

	std::string atual = "q0"; // Estado atual - Começa no estado inicial
	std::set<std::string> finais = {"q2"}; // Conjunto de estados finais
	std::map<std::pair<std::string, char>, std::string> delta; // Função de transição

	// Define a string placa e le a sua entrada
	std::string placa;
	std::getline(std::cin, placa);


	// Percorre a string placa e atualiza o estado atual com base na função de transição
	for (int i = 0; i < placa.size(); i++) {
		char c = placa[i];
		

		if (delta.count({ atual, c }) == 0) return 0; // se a transição não existir, a placa é inválida
		atual = delta[{ atual, c }]; // Atualiza o estado atual com base na função de transição
		if ((c < 'A' || c > 'Z') && (c < '0' || c > '9') && (c != '-')) return 0; // se o caractere não for uma letra, número ou hífen, a placa é inválida
	}

	// Verifica se o estado atual é final
	finais.count(atual) > 0 ? std::cout << "Placa válida" : std::cout << "Placa inválida"; 

	std::cout << std::endl;

	return 0;
}
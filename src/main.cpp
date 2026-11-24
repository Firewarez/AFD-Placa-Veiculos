// Automato finito determinístico (AFD) para validar placas de veículos
// Lib MAP usada para armazenar a função de transição do autômato
// Lib Utility usada para armazenar o par de estado e caractere como chave do map

#include <iostream>
#include <map>
#include <utility>
#include <set>

void RegEx(std::string n) {

	std::string atual = "q0"; // Estado atual - Começa no estado inicial
	std::set<std::string> finais = { "q7_ant", "q7_m" }; // Conjunto de estados finais
	std::map<std::pair<std::string, char>, std::string> delta; // Função de transição

	// Define a string placa e le a sua entrada
	std::string placa;
	std::getline(std::cin, placa);
	int contador = 0; // Contador para verificar o tamanho da placa

	delta[{"q4", '-'}] = "q5_ant";

	for (char l = 'A'; l <= 'Z'; l++) {
		delta[{"q4", l}] = "q5_mercosul";
		for (char d = '0'; d <= '9'; d++) {
			delta[{"q5_mercosul", d}] = "q6_mercosul";
			delta[{"q6_mercosul", d}] = "q7_m";
		}
	}

	for (char d = '0'; d <= '9'; d++) {
		delta[{"q4", d}] = "q5_ant";
		delta[{"q5_ant", d}] = "q6_ant";
		delta[{"q6_ant", d}] = "q7_ant";
	}

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

	return;
}

int main() {

	

	return 0;
}
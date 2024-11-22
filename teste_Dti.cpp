#include <iostream>
#include <vector>

void addVet(std::vector<int>& vet, std::vector<int>& vetFinal, int* posNums) {
	vetFinal.push_back(vet[*posNums]);
	(*posNums)++;
}

void resultado(std::vector<int>& result) {

	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 0) {
			result.erase(result.begin() + i);
		}
		else {
			std::cout << result[i] << " ";
		}
	}
}

void ordenacao(std::vector<int>& nums1, std::vector<int>& nums2) {

	int posNums1 = 0;
	int posNums2 = 0;

	int tamNums1 = nums1.size();
	int tamNums2 = nums2.size();

	for (int i = 0; i < tamNums1 + tamNums2; i++) {

		if (posNums1 >= tamNums1) {			// vetor 1 totalmente percorrido
			nums1.push_back(nums2[posNums2]);
			posNums2++;
		}
		else if (posNums2 >= tamNums2) {	// vetor 2 totalmente percorrido
			return;
		}
		else if ((nums1[posNums1] <= nums2[posNums2]) && nums1[posNums1] != 0) {	// elemento do vetor 1 menor ou igual que o elemento do vetor 2
			posNums1++;
		}
		else {										// elemento do vetor 2 menor que o elemento do vetor 1
			nums1.insert(nums1.begin() + posNums1, nums2[posNums2]);
			posNums2++;
			tamNums1++;
		}
	}
}

void padrao() {
	
	std::vector<int> nums1 = { 1, 1, 3, 5, 7, 9, 0, 0, 0, 0, 0 };
	std::vector<int> nums2 = { 2, 6, 7, 11, 12 };

	ordenacao(nums1, nums2);
	resultado(nums1);
}

void personalizado() {

	int n, m, num;
	std::vector<int> nums1;
	std::vector<int> nums2;

	std::cout << "Digite o tamanho do vetor nums1: ";
	std::cin >> n;

	std::cout << "Digite o tamanho do vetor nums2: ";
	std::cin >> m;

	for (int i = 0; i < n; i++) {
		std::cout << "Digite o numero na posicao " << i << " do vetor nums1: ";
		std::cin >> num;
		nums1.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		std::cout << "Digite o numero na posicao " << i << " do vetor nums2: ";
		std::cin >> num;
		nums2.push_back(num);
	}

	ordenacao(nums1, nums2);
	resultado(nums1);
}

int main(){
    
	int escolha = -1;

	while(escolha != 0 && escolha != 1){
		std::cout << "Digite 1 para personalizar a entrada dos vetores ou 0 para usar uma situacao pre-definida" << std::endl;
		std::cin >> escolha;
	}

	escolha == 0 ? padrao() : personalizado();
}


#include "Character.hpp"

Character::Character() : name("") {
	for (int i = 0; i < NUM_MATERIA; ++i)
		materia[i] = NULL;
}

Character::Character(const std::string &name) : name(name) {
	for (int i = 0; i < NUM_MATERIA; ++i)
		materia[i] = NULL;
}

Character::Character(const Character &a) {
	*this = a;
}

Character::~Character() {
	for (int i = 0; i < NUM_MATERIA; ++i) {
		if (materia[i]) {
			delete materia[i];
		}
	}
}

Character &Character::operator=(const Character &a) {
	this->name = a.getName();
	for (int i = 0; i < NUM_MATERIA; ++i) {
		const AMateria *tmp = a.getMateria(i);
		if (tmp) {
			materia[i] = tmp->clone();
		} else {
			materia[i] = NULL;
		}
	}
	return (*this);
}

std::string const &Character::getName() const {
	return (name);
}

const AMateria *Character::getMateria(int index) const {
	if (!_isValidIndex(index)){
		return (NULL);
	}
	return (materia[index]);
}

// 最初に空いているインデックスに装備する
void Character::equip(AMateria *m) {
	for (int i = 0; i < NUM_MATERIA; ++i) {
		if (materia[i] == NULL) {
			materia[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (!_isValidIndex(idx) || !materia[idx]) {
		return ;
	}
	materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (!_isValidIndex(idx) || !materia[idx]) {
		return ;
	}
	materia[idx]->use(target);
}

bool Character::_isValidIndex(int index) const {
	return (0 <= index && index < NUM_MATERIA);
}

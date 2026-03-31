#include <iostream>
#include "team.h"

namespace JD {

	Team::~Team() {

		for (size_t i = 0; i < m_size; ++i) {
			delete m_members[i];
		}
		delete[] m_members;

	}

	Team::Team(const std::string name) : m_teamName{ name }, m_members{}, m_size{ 0 } {
	}

	Team::Team(const Team& other) {

		m_teamName = other.m_teamName;
		m_size = other.m_size;

		if (m_size == 0) {
			m_members = nullptr;
		}
		else {
			m_members = new Character * [m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_members[i] = other.m_members[i] ? other.m_members[i]->clone() : nullptr;
			}
		}

	}

	Team& Team::operator=(const Team& other) {
		if (this != &other) {

			for (size_t i = 0; i < m_size; ++i) {
				delete m_members[i];
			}
			delete[] m_members;

			m_teamName = other.m_teamName;
			m_size = other.m_size;

			if (m_size == 0) {
				m_members = nullptr;
			}
			else {
				m_members = new Character * [m_size];
				for (size_t i = 0; i < m_size; ++i) {
					if (other.m_members[i] != nullptr) {
						m_members[i] = other.m_members[i]->clone();
					}
					else {
						m_members[i] = nullptr;
					}
				}
			}
		}
		return *this;
	}

	Team::Team(Team&& other) noexcept {
		m_teamName = std::move(other.m_teamName);
		m_members = other.m_members;
		m_size = other.m_size;

		other.m_members = nullptr;
		other.m_size = 0;
	}

	Team& Team::operator=(Team&& other) noexcept {
		if (this != &other) {

			for (size_t i = 0; i < m_size; ++i) {
				delete m_members[i];
			}
			delete[] m_members;

			m_teamName = std::move(other.m_teamName);
			m_members = other.m_members;
			m_size = other.m_size;

			other.m_members = nullptr;
			other.m_size = 0;
		}
		return *this;
	}

	void Team::addMember(const Character* c) {

		if (c)
		{
			bool exists = false;

			for (size_t i = 0; i < m_size && !exists; ++i) {
				if (m_members[i] && m_members[i]->getName() == c->getName()) {
					exists = true;
				}
			}

			if (!exists) {

				Character** temp = new Character * [m_size + 1];

				for (size_t i = 0; i < m_size; ++i) {
					temp[i] = m_members[i];
				}

				temp[m_size] = c->clone();

				delete[] m_members;

				m_members = temp;
				++m_size;
			}
		}



	}

	void Team::removeMember(const std::string& c) {
		if (m_size != 0 && m_members) {

			size_t idx = m_size;
			for (size_t i = 0; i < m_size; ++i) {
				if (m_members[i] && m_members[i]->getName() == c) {
					idx = i;
				}
			}

			if (idx != m_size) {

				delete m_members[idx];

				if (m_size == 1) {
					delete[] m_members;
					m_members = nullptr;
					m_size = 0;
				}
				else {
					Character** temp = new Character * [m_size - 1];

					for (size_t i = 0, j = 0; i < m_size; ++i) {
						if (i != idx) {
							temp[j++] = m_members[i];
						}
					}

					delete[] m_members;
					m_members = temp;
					--m_size;
				}
			}
		}
	}

	void Team::showMembers() const {
		if (m_teamName.empty()) {
			std::cout << "No team." << std::endl;
			return;
		}

		std::cout << "[Team] " << m_teamName << std::endl;

		for (size_t i = 0; i < m_size; ++i) {
			std::cout << "    " << (i + 1) << ": ";
			if (m_members[i]) {
				std::cout << *m_members[i] << std::endl;
			}
			else {
				std::cout << "(null)" << std::endl;
			}
		}
	}

	Character* Team::operator[](size_t idx) const {

		Character* result = nullptr;

		if (m_members && idx < m_size) {
			result = m_members[idx];
		}

		return result;
	}

}
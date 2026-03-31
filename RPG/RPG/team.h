#ifndef JD_TEAM_H
#define JD_TEAM_H
#include <string>
#include "character.h"

namespace JD {

	class Team
	{
		std::string m_teamName{};
		Character** m_members{};
		size_t m_size{};


	public:
		Team() = default;
		Team(const std::string name);

		Team(const Team& other);
		Team& operator=(const Team& other);
		Team(Team&& other) noexcept;
		Team& operator=(Team&& other) noexcept;
		~Team();

		void addMember(const Character* c);

		void removeMember(const std::string& c);

		Character* operator[](size_t idx) const;

		void showMembers() const;

	};
}

#endif

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

#define MAX_IDEAS 100

class Brain {
  public:
	  Brain();
	  Brain(const Brain &other);
	  Brain &operator=(const Brain &other);
	  ~Brain();

	  std::string getIdea(int index) const;
	  void setIdea(int index, const std::string &idea);

  private:
	  std::string _ideas[MAX_IDEAS];
};

#endif

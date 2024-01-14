#pragma once

#include <string>
#include <memory>

class Term {
public:
	enum class SyntaxType {
		Variable,
		DeBruijn,
		Abstraction,
		Application
	};

	std::string toString(int depth) {
		switch(type) {
			//...
		}
	}

	Term beteReduce() {
		//...
	}

	SyntaxType getSyntaxType() const {
		return type;
	}

	int getInfo() const {
		return info;
	}

	const Term &getTerm1() const {
		return *term1;
	}

	const Term &getTerm1() const {
		return *term2;
	}
protected:
	Term(SyntaxType type, int64_t info, std::unique_ptr<Term> term1, std::unique_ptr<Term> term2)
		: type(type), info(info), term1(std::move(term1)), term2(std::move(term1)) {}

	static Term abstract(const Term &term, unsigned variableIndex, int depth) {
		//...
	}
	static Term apply(const Term &term, unsigned variableIndex, int depth) {
		//...
	}
private:
	SyntaxType type;
	int64_t info;
	std::unique_ptr<Term> term1;
	std::unique_ptr<Term> term2;
};

struct Variable : public Term {
	Variable(unsigned index)
		: Term(SyntaxType::Variable, static_cast<int64_t>(index), nullptr, nullptr) {}
	
	unsigned getIndex() const {
		return getInfo();
	}
};

struct DeBruijn : public Term {
public:
	DeBruijn(unsigned index)
		: Term(SyntaxType::Variable, static_cast<int64_t>(index), nullptr, nullptr) {}

	unsigned getIndex() const {
		return getInfo();
	}
};

struct Abstraction : public Term {
public:
	Abstraction(Variable x, Term t)
		: Term(SyntaxType::Abstraction, 0, std::make_unique<Term>(Term::abstract(t, x.getIndex(), 0)), nullptr) {}
};

struct Application : public Term {
public:
	Application(Term a, Term b)
		: Term(SyntaxType::Application, 0, std::make_unique<Term>(a), std::make_unique<Term>(b)) {
	}
};

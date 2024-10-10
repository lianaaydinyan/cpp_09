#include "RPN.hpp"

rpn_calculator::rpn_calculator() {}

rpn_calculator::~rpn_calculator() {}

int rpn_calculator::calculator(char op)
{
	if (container.size() < 2)
		throw std::runtime_error("Error: Malformed RPN expression");

	tmp_r = container.top();
	container.pop();
	tmp_l = container.top();
	container.pop();
	if (op == '/')
		division_check(tmp_r);

	int result = (op == '+') ? (tmp_l + tmp_r) :
				 (op == '-') ? (tmp_l - tmp_r) :
				 (op == '*') ? (tmp_l * tmp_r) :
							   (tmp_l / tmp_r);

	container.push(result);
	return result;
}

void rpn_calculator::division_check(int right_operand)
{
	if (right_operand == 0)
	{
		throw std::runtime_error("Error: Division by zero");
	}
}

void rpn_calculator::fill_the_container(std::string &str)
{
	for (size_t index = 0; index < str.size(); ++index)
	{
		if (std::isspace(str[index]))
			continue;
		if (std::isdigit(str[index]))
			container.push(str[index] - '0');
		else if (valid_op(str[index]))
			calculator(str[index]);
		else
			throw std::runtime_error("Error: Invalid character in RPN expression");
	}
	if (container.size() == 1)
		std::cout << container.top() << std::endl;
	else
		throw std::runtime_error("Error: Malformed RPN expression");
}

bool rpn_calculator::valid_op(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

void rpn_calculator::scaning(char **av)
{
	size_t i = 1;
	int j = 1;
	std::string line;
	while (j < ac )
	{
		line += av[j];
		line += " ";
		j++;
	}
	i = 0;
	size_t len = line.length();

	while (std::isspace(line[i]))
		i++;
	if (i == len)
		throw std::runtime_error("Enter digits and operands >_<");

	i = 0;
	while (i < line.length())
	{
		if (!std::isspace(line[i]) && !std::isdigit(line[i]) && !valid_op(line[i]))
			throw std::runtime_error("invalid character");
		if (std::isdigit(line[i]) && line[i + 1] && std::isdigit(line[i + 1]))
			throw std::runtime_error("only single digits!");
		if (valid_op(line[i]) && line[i + 1] && !(std::isspace(line[i + 1]) || std::isdigit(line[i + 1])))
			throw std::runtime_error("invalid syntax!");
		i++;
	}

	fill_the_container(line);
}

void rpn_calculator::rpn(char **av)
{
	scaning(av);
}


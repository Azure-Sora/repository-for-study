
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linker.h"
FILE* in;   //for read module
FILE* out;  //for output link result

/*offset of the current moudle
  assume current module is I+1, the offset of I+1
  will be LENGTH(0) + LENGTH(1) + ...... LENGTH(I)
  where the LENGTH(I) reprent the length of module I
*/
int offset = 0;
int module_now = 0;
int modules_count = 0;
int symbols_count = 0;
int uses_count = 0;
int instructions_count = 0;

typedef struct
{
	char* symbol_name;
	int module;
	int relative_position;
	int absolute_position;
}symbol;

typedef struct
{
	char type;
	int code;
	char* err_info;
}instruction;

typedef struct
{
	char* use_name;
	int first_use;
	int module;
}use;

typedef struct
{
	int length;
	int use_cnt;
}module;

symbol* symbols;
instruction* instructions;
use* uses;
module* modules;

void link(int test_num, const char* filename)
{
	char outputfile[20];
	memset(outputfile, 0, 10);
	sprintf(outputfile, "output-%d.txt", test_num);
	in = fopen(filename, "r");    //open file for read,the file contains module that you should do with
	out = fopen(outputfile, "w"); //open the "output" file to output link result
	if (in == NULL || out == NULL)
	{
		fprintf(stderr, "can not open file for read or write\n");
		exit(-1);
	}

	symbols = malloc(255 * sizeof(symbol));
	uses = malloc(255 * sizeof(use));
	instructions = malloc(1024 * sizeof(instruction));
	modules = malloc(255 * sizeof(module));

	process_one(); //resolve
	process_two(); //relocate
	free(symbols);
	free(instructions);
	free(modules);
	free(uses);
	fclose(in);
	fclose(out);
}

char is_ch_empty(char ch)
{
	return (ch == '\0' || ch == ' ' || ch == '\n' || ch == '\t');
}

int find_first_match_symbol_index(char* name)
{
	int i = 0;
	for (; i < symbols_count; i++)
	{
		if (strcmp(name, symbols[i].symbol_name) == 0)
		{
			symbols[i].relative_position = -1;
			return i;
		}
	}
	return -1;
}

char is_symbol_output(char* name, char** symbol_exists)
{
	int i = 0;
	for (; i < symbols_count; i++)
	{
		if (symbol_exists[i] == NULL) return 0;
		if (strcmp(name, symbol_exists[i]) == 0) return 1;
	}
	return 0;
}

char is_symbol_to_be_repeated(char* name, int in)
{
	int i = in + 1;
	for (; i < symbols_count; i++)
	{
		if (strcmp(name, symbols[i].symbol_name) == 0) return 1;
	}
	return 0;
}

/*you must implement this function*/
void process_one()
{
	offset = 0;
	module_now = 0;
	char ch = 0;
	int i, j;
	while (ch != EOF)
	{
		//get symbol definitions
		char def_string[10] = { '\0' };
		while (is_ch_empty(ch)) ch = fgetc(in);
		i = 0;
		do
		{
			def_string[i] = ch;
			i++;
			ch = fgetc(in);
		} while (!is_ch_empty(ch));
		int def_count = atoi(def_string);
		i = 0;
		while (i < def_count)
		{
			char* symbol_name = malloc(10 * sizeof(char));
			memset(symbol_name, 0, 10);
			j = 0;

			while (is_ch_empty(ch)) ch = fgetc(in);
			do
			{
				symbol_name[j] = ch;
				j++;
				ch = fgetc(in);
			} while (!is_ch_empty(ch));
			char sym_rela_pos_str[10] = { '\0' };
			while (is_ch_empty(ch)) ch = fgetc(in);
			j = 0;
			do
			{
				sym_rela_pos_str[j] = ch;
				j++;
				ch = fgetc(in);
			} while (!is_ch_empty(ch));
			symbols[symbols_count].symbol_name = symbol_name;
			symbols[symbols_count].relative_position = atoi(sym_rela_pos_str);
			symbols[symbols_count].module = module_now;
			symbols_count++;
			i++;
		}

		//get uses
		char use_cnt_str[10] = { '\0' };
		i = 0;
		while (is_ch_empty(ch)) ch = fgetc(in);
		do
		{
			use_cnt_str[i] = ch;
			i++;
			ch = fgetc(in);
		} while (!is_ch_empty(ch));
		int use_cnt = atoi(use_cnt_str);
		i = 0;
		while (is_ch_empty(ch)) ch = fgetc(in);
		while (i < use_cnt)
		{
			char* use_name = malloc(10 * sizeof(char));
			memset(use_name, 0, 10);
			j = 0;

			while (is_ch_empty(ch)) ch = fgetc(in);
			do
			{
				use_name[j] = ch;
				j++;
				ch = fgetc(in);
			} while (!is_ch_empty(ch));
			char use_pos_str[10] = { '\0' };
			while (is_ch_empty(ch)) ch = fgetc(in);
			j = 0;
			do
			{
				use_pos_str[j] = ch;
				j++;
				ch = fgetc(in);
			} while (!is_ch_empty(ch));
			uses[uses_count].use_name = use_name;
			uses[uses_count].first_use = atoi(use_pos_str);
			uses[uses_count].module = module_now;
			uses_count++;
			i++;
		}

		//get instructions
		char ins_cnt_str[10] = { '\0' };
		i = 0;
		while (is_ch_empty(ch)) ch = fgetc(in);
		do
		{
			ins_cnt_str[i] = ch;
			i++;
			ch = fgetc(in);
		} while (!is_ch_empty(ch));
		int ins_cnt = atoi(ins_cnt_str);
		int module_length = ins_cnt;

		i = 0;
		while (is_ch_empty(ch)) ch = fgetc(in);
		while (i < ins_cnt)
		{
			char ins_type;
			while (is_ch_empty(ch)) ch = fgetc(in);
			ins_type = ch;
			ch = fgetc(in);
			char ins[10] = { '\0' };
			while (is_ch_empty(ch)) ch = fgetc(in);
			j = 0;
			do
			{
				ins[j] = ch;
				j++;
				ch = fgetc(in);
			} while (!is_ch_empty(ch));

			instructions[instructions_count].type = ins_type;
			instructions[instructions_count].code = atoi(ins);
			instructions[instructions_count].err_info = NULL;
			instructions_count++;
			i++;
		}
		//a module finished

		modules[module_now].length = module_length;
		modules[module_now].use_cnt = use_cnt;
		modules_count++;
		module_now++;

		while (is_ch_empty(ch)) ch = fgetc(in);
		if (ch == EOF) break;
	}
	//finish read

	for (i = 0; i < symbols_count; i++)
	{
		int base = 0;
		for (j = 0; j < symbols[i].module; j++)
		{
			base += modules[j].length;
		}
		if (symbols[i].relative_position > modules[symbols[i].module].length - 1)
		{
			symbols[i].absolute_position = base;
			symbols[i].relative_position = -2;
		}
		else
		{
			symbols[i].absolute_position = base + symbols[i].relative_position;
		}
	}
}

/*you must implement this function*/
void process_two()
{
	fputs("Symbol Table\n", out);

	char** symbol_output = malloc(symbols_count * sizeof(char*));
	memset(symbol_output, 0, symbols_count * sizeof(char*));
	int i;

	for (i = 0; i < symbols_count; i++)
	{
		if (!is_symbol_output(symbols[i].symbol_name, symbol_output))
		{
			if (symbols[i].relative_position == -2)
			{
				fprintf(out, "%s=%d Error: The value of %s is outside module %d; zero (relative) used", symbols[i].symbol_name, symbols[i].absolute_position, symbols[i].symbol_name, symbols[i].module + 1);
			}
			else
			{
				fprintf(out, "%s=%d", symbols[i].symbol_name, symbols[i].absolute_position);
			}
			if (is_symbol_to_be_repeated(symbols[i].symbol_name, i))
			{
				fputs(" Error: This variable is multiply defined; first value used.\n", out);
			}
			else
			{
				fputs("\n", out);
			}
		}
		else
		{
			symbols[i].absolute_position = -1;
		}
		symbol_output[i] = symbols[i].symbol_name;
	}

	free(symbol_output);
	//symbol table end

	module_now = 0;
	int ins_base = 0;
	int use_base = 0;
	while (module_now < modules_count)
	{
		i = 0;
		while (i < modules[module_now].use_cnt)
		{
			int ins_rela_pos = uses[use_base + i].first_use;
			int ins_pos = ins_rela_pos + ins_base;
			while (1)
			{
				switch (instructions[ins_pos].type)
				{
				case 'R':
					instructions[ins_pos].err_info = "Error: R type address on use chain; treated as E type.";
					break;
				case 'A':
					instructions[ins_pos].err_info = "Error: A type address on use chain; treated as E type.";
					break;
				case 'I':
					instructions[ins_pos].err_info = "Error: I type address on use chain; treated as E type.";
				}

				int code = instructions[ins_pos].code;
				int ins_next_rela_pos = code % 1000;
				int symbol_index = find_first_match_symbol_index(uses[use_base + i].use_name);
				int ab_operand;
				if (symbol_index == -1)
				{
					ab_operand = 0;
					instructions[ins_pos].err_info = malloc(50 * sizeof(char));
					sprintf(instructions[ins_pos].err_info, "Error: %s is not defined; zero used.", uses[use_base + i].use_name);
				}
				else
				{
					ab_operand = symbols[symbol_index].absolute_position;
				}
				instructions[ins_pos].code = code / 1000 * 1000 + ab_operand;
				instructions[ins_pos].type = 'e';
				if (ins_next_rela_pos == 777) break;
				if (ins_next_rela_pos >= modules[module_now].length)
				{
					instructions[ins_pos].err_info = "Error: Pointer in use chain exceeds module size; chain terminated.";
					break;
				}
				ins_pos = ins_next_rela_pos + ins_base;
			}
			i++;
		}
		i = 0;
		while (i < modules[module_now].length)
		{
			if (instructions[ins_base + i].type == 'R')
			{
				instructions[ins_base + i].code = instructions[ins_base + i].code + ins_base;
			}
			i++;
		}
		use_base += modules[module_now].use_cnt;
		ins_base += modules[module_now].length;
		module_now++;
	}

	fputs("\nMemory Map\n", out);

	for (i = 0; i < instructions_count; i++)
	{
		if (instructions[i].type == 'E')
		{
			instructions[i].err_info = "Error: E type address not on use chain; treated as I type.";
		}
		if (instructions[i].err_info == NULL)
		{
			fprintf(out, "%d: %d\n", i, instructions[i].code);
		}
		else
		{
			fprintf(out, "%d: %d %s\n", i, instructions[i].code, instructions[i].err_info);
		}

	}

	fputs("\n", out);
	for (i = 0; i < symbols_count; i++)
	{
		if (symbols[i].absolute_position != -1 && symbols[i].relative_position != -1)
		{
			fprintf(out, "Warning: %s was defined in module %d but never used.\n", symbols[i].symbol_name, symbols[i].module + 1);
		}
	}
}



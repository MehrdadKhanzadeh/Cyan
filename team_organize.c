void swapPlayers(int team_num,int player1,int player2)//swap 2 players attributes 
{
	char name_temp[100], post_temp;
	int int_temp;
	//name change
	name_temp = teams[team_num].players[player1].name;
	teams[team_num].players[player1].name = teams[team_num].players[player2].name;
	teams[team_num].players[player2].name = name_temp;
	//post change
	post_temp = teams[team_num].players[player1].original_post;
	teams[team_num].players[player1].original_post = teams[team_num].players[player2].original_post;
	teams[team_num].players[player2].original_post = post_temp;
	
	post_temp = teams[team_num].players[player1].post;
	teams[team_num].players[player1].post = teams[team_num].players[player2].post;
	teams[team_num].players[player2].post = post_temp;
	
	//age change
	int_temp = teams[team_num].players[player1].age;
	teams[team_num].players[player1].age = teams[team_num].players[player2].age;
	teams[team_num].players[player2].age = int_temp;
	//number change
	int_temp = teams[team_num].players[player1].number;
	teams[team_num].players[player1].number = teams[team_num].players[player2].number;
	teams[team_num].players[player2].number = int_temp;
	//skill change
	int_temp = teams[team_num].players[player1].skill;
	teams[team_num].players[player1].skill = teams[team_num].players[player2].skill;
	teams[team_num].players[player2].skill = int_temp;
	//base skill change 
	int_temp = teams[team_num].players[player1].base_skill;
	teams[team_num].players[player1].base_skill = teams[team_num].players[player2].base_skill;
	teams[team_num].players[player2].base_skill = int_temp;
	//fitness
	int_temp = teams[team_num].players[player1].fitness;
	teams[team_num].players[player1].fitness = teams[team_num].players[player2].fitness;
	teams[team_num].players[player2].fitness = int_temp;
	//form
	int_temp = teams[team_num].players[player1].form;
	teams[team_num].players[player1].form = teams[team_num].players[player2].form;
	teams[team_num].players[player2].form = int_temp;
}
int playerOverall(int team_num, int player_num)//calculates player overall
{
	return (0.5 * teams[team_num].players[player_num].skill + 0.3 * teams[team_num].players[player_num].form + 0.3 * teams[team_num].players[player_num].fitness);
}
void teamSort(int team_num)//sort the team
{
	int i,j;
	for (i = 0 ; i < teams[team_num].player_count ; i++)
	{
		for(j = i ; j < teams[team_num].player_count ; j++)
		{
			if(playerOverall(team_num,i) < playerOverall(team_num,j))
				swapPlayers(team_num, i, j);
		}
	}
	switch(teams[team_num].formation)
	{
		case 1 ://4-4-2
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
					teams[team_num].fix_players[0].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number; 	
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 9)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 2 ://4-3-3
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
					teams[team_num].fix_players[0].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number; 	
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 8)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 3 ://5-4-1
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
					teams[team_num].fix_players[0].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number; 	
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 6)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 10)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 11)
						break;
				}
			}
			break;
		case 3 ://3-5-2
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'G')
				{
					teams[team_num].fix_players[0].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[0].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[0].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[0].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[0].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[0].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[0].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[0].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[0].number = teams[team_num].players[i].number; 	
					break;
				}
			}
			j = 1;
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 5)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'D')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 4)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'M')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 9)
						break;
				}
			}
			for(i = 0 ; i < teams[team_num].player_count ; i++)
			{
				if(teams[team_num].players[i].post == 'A')
				{
					teams[team_num].fix_players[j].name = teams[team_num].players[i].name; 	
					teams[team_num].fix_players[j].original_post = teams[team_num].players[i].post; 	
					teams[team_num].fix_players[j].post = teams[team_num].players[i].post;
					teams[team_num].fix_players[j].age = teams[team_num].players[i].age; 	
				 	teams[team_num].fix_players[j].skill = teams[team_num].players[i].skill;
					teams[team_num].fix_players[j].base_skill = teams[team_num].players[i].base_skill; 	
					teams[team_num].fix_players[j].fitness = teams[team_num].players[i].fitness;
					teams[team_num].fix_players[j].form = teams[team_num].players[i].form; 	
					teams[team_num].fix_players[j].number = teams[team_num].players[i].number; 	
					j++;
					if (j == 11)
						break;
				}
			}
			break;
	}
}



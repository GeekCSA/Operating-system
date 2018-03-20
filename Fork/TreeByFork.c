/*
 ============================================================================
 Name        : TreeByFork.c
 Author      : Moshe
 Version     :
 Copyright   : Your copyright notice
 Description : Build tree of processes by  in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<sys/wait.h>

int main(void) {

	int x;
	int sum = 0;

	pid_t a = fork();//Create #2
	if(a == 0)//Is #2
	{
		pid_t a = fork();//Create #4
		if(a == 0)//Is #4
		{
			pid_t a = fork();//Create #8
			if(a == 0)//Is #8
			{
				pid_t a = fork();//Create #14
				if(a == 0)//Is #14
				{
					int child = 1;
					return child;
				}
				else
				{
					pid_t a = fork();//Create #15
					if(a == 0)//Is #15
					{
						int child = 1;//It for his father is one child.
						return child;
					}

					int child;
					int temp;
					wait(&child);//Wait for #14
					child /= 256;
					wait(&temp);//Wait for #15
					child += temp/256;

					printf("The number of children (include me - 8 - ) is %d\n",child);
					child++;//Add one for correct node which child for his father
					return child;
				}
			}
			else
			{
				pid_t a = fork();//Create #9
				if(a == 0)//Is #9
				{
					pid_t a = fork();//Create #16
					if(a == 0)//Is #16
					{
						pid_t a = fork();//Create #22
						if(a == 0)//Is #22
						{
							pid_t a = fork();//Create #26
							if(a == 0)//Is #26
							{
								int child = 1;
								return child;
							}
							else
							{
								pid_t a = fork();//Create #27
								if(a == 0)//Is #27
								{
									int child = 1;
									return child;
								}

								int child;
								int temp;
								wait(&child);//Wait for #26
								child /= 256;
								wait(&temp);//Wait for #27
								child += temp/256;

								printf("The number of children (include me - 22 - ) is %d\n",child);
								child++;//Add one for correct node which child for his father
								return child;
							}
						}
						else
						{
							pid_t a = fork();//Create #23
							if(a == 0)//Is #23
							{
								int child = 1;
								return child;
							}

							int child;
							int temp;
							wait(&child);//Wait for #22
							child /= 256;
							wait(&temp);//Wait for #23
							child += temp/256;

							printf("The number of children (include me - 16 - ) is %d\n",child);
							child++;//Add one for correct node which child for his father
							return child;
						}
					}
					else
					{
						pid_t a = fork();//Create #17
						if(a == 0)//Is #17
						{
							int child = 1;
							return child;
						}

						int child;
						int temp;
						wait(&child);//Wait for #16
						child /= 256;
						wait(&temp);//Wait for #17
						child += temp/256;

						printf("The number of children (include me - 9 - ) is %d\n",child);
						child++;//Add one for correct node which child for his father
						return child;
					}
				}

				int child;
				int temp;
				wait(&child);//Wait for #8
				child /= 256;
				wait(&temp);//Wait for #9
				child += temp/256;

				printf("The number of children (include me - 4 - ) is %d\n",child);
				child++;//Add one for correct node which child for his father
				return child;
			}
		}
		else//Is #2
		{
			pid_t a = fork();//Create #5
			if(a == 0)//Is 5
			{
				pid_t a = fork();//Create #10
				if(a == 0)//Is #10
				{
					int child = 1;
					return child;
				}
				else//Is #5 - father of #10
				{
					pid_t a = fork();//Create #11
					if(a == 0)//Is #11
					{
						pid_t a = fork();//Create #19
						if(a == 0)//Is #19
						{
							int child = 1;
							return child;
						}
						else
						{
							pid_t a = fork();//Create #18
							if(a == 0)//Is #18
							{
								pid_t a = fork();//Create #24
								if(a == 0)//Is #24
								{
									int child = 1;
									return child;
								}
								else
								{
									pid_t a = fork();//Create #25
									if(a == 0)//Is #25
									{
										int child = 1;
										return child;
									}

									int child;
									int temp;
									wait(&child);//Wait for #24
									child /= 256;
									wait(&temp);//Wait for #25
									child += temp/256;

									printf("The number of children (include me - 18 - ) is %d\n",child);
									child++;//Add one for correct node which child for his father
									return child;
								}
							}

							int child;
							int temp;
							wait(&child);//Wait for #18
							child /= 256;
							wait(&temp);//Wait for #19
							child += temp/256;

							printf("The number of children (include me - 11 - ) is %d\n",child);
							child++;//Add one for correct node which child for his father
							return child;

						}
					}
					else
					{
						int child;
						int temp;
						wait(&child);//Wait for #10
						child /= 256;
						wait(&temp);//Wait for #11
						child += temp/256;

						printf("The number of children (include me - 5 - ) is %d\n",child);
						child++;//Add one for correct node which child for his father
						return child;
					}
				}
			}
			else//Is 2
			{
				int child;
				int temp;
				wait(&child);//Wait for #5
				child /= 256;
				wait(&temp);//Wait for #4
				child += temp/256;

				printf("The number of children (include me - 2 - ) is %d\n",child);
				child++;//Add one for correct node which child for his father
				return child;
			}
		}
	}
	else
	{
		pid_t a = fork();//Create #3
		if(a == 0)
		{
			pid_t a = fork();//Create #6
			if(a == 0)//Is #6
			{
				int child = 1;
				return child;
			}
			else
			{
				pid_t a = fork();//Create #7
				if(a == 0)//Is #7
				{
					pid_t a = fork();//#13
					if(a == 0)//Is #13
					{
						int child = 1;
						return child;
					}
					else
					{
						pid_t a = fork();//Create #12
						if(a == 0)//Is #12
						{
							pid_t a = fork();//Create #20
							if(a == 0)//Is #20
							{
								int child = 1;
								return child;
							}
							else
							{
								pid_t a = fork();//Create #21
								if(a == 0)//Is #21
								{
									int child = 1;
									return child;
								}
								int child;
								int temp;
								wait(&child);//Wait for #20
								child /= 256;
								wait(&temp);//Wait for #21
								child += temp/256;

								printf("The number of children (include me - 12 - ) is %d\n",child);
								child++;//Add one for correct node which child for his father
								return child;
							}
						}

						int child;
						int temp;
						wait(&child);//Wait for #6
						child /= 256;
						wait(&temp);//Wait for #7
						child += temp/256;

						printf("The number of children (include me - 7 - ) is %d\n",child);
						child++;//Add one for correct node which child for his father
						return child;
					}
				}
				int child;
				int temp;
				wait(&child);//Wait for #6
				child /= 256;
				wait(&temp);//Wait for #7
				child += temp/256;

				printf("The number of children (include me - 3 - ) is %d\n",child);
				child++;//Add one for correct node which child for his father
				return child;
			}
		}


		wait(&x);
		sum = x/256;
		wait(&x);
		sum += x/256;
		printf("The number of all children , The x number is %d\n",sum);
		puts("Father");
	}


	puts("!!!Hello World!!!");
	return EXIT_SUCCESS;
}

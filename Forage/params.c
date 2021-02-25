/* params.c
   08.15.26.AW	Created.
		Adapted from same file in the GA code.
		Routines that have to do with reading in
		parameter values from both the parameter
		and opfiles files.

   Routines:	read_defaults()		06.18.98.AW
		read_params()		06.18.98.AW
		get_next_line()		06.18.98.AW
		set_param()		06.21.98.AW
		read_default_opfiles()	06.21.98.AW
		read_opfiles()		06.21.98.AW
		get_file_pointer()	06.21.98.AW
		setup_output_files()	07.03.98.AW
		file_on()		07.27.98.AW
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "extern.h"
#include "params.h"
#include "output.h"

/********** read_defaults **********/
/* parameters:
   called by:	init_sim(), sim.c
   actions:	Reads in default parameter and opfile values
		from the files: params and opfiles.
*/
int read_defaults()
   {
#ifdef DEBUG
   printf(" ---in read_defaults()---\n");
#endif
  /* read values from params */
   if (read_params("params.default") == ERROR)  return ERROR;
  /* read values from opfiles */
   if (read_default_opfiles("opfiles.default") == ERROR)  return ERROR;
#ifdef DEBUG
   printf(" ---end read_defaults()---\n");
#endif
   return OK;
   }  /* read_defaults */

/********** read_params **********/
/* parameters:  params_file
   called by:   init_sim(), sim.c
                read_defaults, params.c
   actions:     Read from specified params file, one line at
                a time and set the correct parameter value
                in global.h.
                Skip the comment lines which are denoted
                by a "#" or "%" xter in the first column.
		Each line contains the name of a parameter
		followed by its value.
*/
int read_params(char *params_file)
   {
   FILE *fp;
   char *aline;

#ifdef DEBUG
   printf(" ---in read_params()--- %s\n", params_file);
#endif
  /* open input file */
   fp = fopen(params_file, "r");
   if (fp == NULL)
      {
      printf(" Error(read_params): cannot open file: %s\n", params_file);
      return ERROR;
      }  /* if */
   printf(" **** Reading from file: %s\n", params_file);

  /* allocate space for aline */
   aline = (char *)malloc(INPUT_LINE_LEN * sizeof(char));

   while (get_next_line(fp, aline) != ENDOFFILE)
      {
      if (set_param(aline) == ERROR)  return ERROR;
      }  /* while */

   free(aline);
   fclose(fp);
#ifdef DEBUG
   printf(" ---end read_params()---\n");
#endif
   return OK;
   }  /* read_params */

/********** get_next_line **********/
/* parameters:  fp			file to read from
		aline                   temp string for parsing comments
   called by:   read_params(), params.c
   actions:     Read the next non-comment line from fp into aline.
*/
int get_next_line(FILE *fp, char *aline)
   {
#ifdef DEBUG
   printf(" ---in get_next_line()---\n");
#endif
   do 
      {
      aline = fgets(aline, INPUT_LINE_LEN, fp);
      if (aline == NULL)  return ENDOFFILE;
      }
   while (aline[0] == '#');

#ifdef DEBUG
   printf(" ---end get_next_line()---\n");
#endif
   return OK;
   }  /* get_next_line */

/********** set_param **********/
/* parameters:  aline			temp string for parsing comments
   called by:   read_params(), params.c
   actions:     set the parameter value specified in aline.
*/
int set_param(char *aline)
   {
   char name[100];
   char temp[100];

#ifdef DEBUG
   printf(" ---in set_param()--- \n");
#endif

   sscanf(aline, "%s %s", name, temp);

   if (!strcmp(name, "Rerun"))  sscanf(temp, "%d", &Rerun);
   else if (!strcmp(name, "Run_num_file"))  sscanf(temp, "%s", Run_num_file);
   else if (!strcmp(name, "Output_path"))  sscanf(temp, "%s", Output_path);
   else if (!strcmp(name, "Print_params"))  sscanf(temp, "%d", &Print_params);
   else if (!strcmp(name, "Max_steps"))  sscanf(temp, "%d", &Max_steps);
   else if (!strcmp(name, "Pop_size"))  sscanf(temp, "%d", &Pop_size);
   else if (!strcmp(name, "Init_thresh"))  sscanf(temp, "%lf", &Init_thresh);
   else if (!strcmp(name, "Max_thresh"))  sscanf(temp, "%lf", &Max_thresh);
   else if (!strcmp(name, "Min_thresh"))  sscanf(temp, "%lf", &Min_thresh);
   else if (!strcmp(name, "Prob_check"))  sscanf(temp, "%lf", &Prob_check);
   else if (!strcmp(name, "Grid_height"))  sscanf(temp, "%d", &Envr.height);
   else if (!strcmp(name, "Grid_width"))  sscanf(temp, "%d", &Envr.width);
   else if (!strcmp(name, "Num_food"))  sscanf(temp, "%d", &Envr.num_food);
   else if (!strcmp(name, "Init_food"))  sscanf(temp, "%s", Envr.init_food);
   else if (!strcmp(name, "Need"))  sscanf(temp, "%d", &Nest.need);
   else if (!strcmp(name, "Response_prob")) sscanf(temp, "%lf", &Response_prob);
   else if (!strcmp(name, "Max_sim_time"))  sscanf(temp, "%d", &Max_sim_time);
   else if (!strcmp(name, "Print_agent_paths")) sscanf(temp, "%d", &Print_agent_paths);
   else if (!strcmp(name, "Print_agent_memory")) sscanf(temp, "%d", &Print_agent_memory);
   else if (!strcmp(name, "Print_agent_final_memory")) sscanf(temp, "%d", &Print_agent_final_memory);
   else if (!strcmp(name, "Positive_reinforcement")) sscanf(temp, "%lf", &Positive_reinforcement);
   else if (!strcmp(name, "Negative_reinforcement")) sscanf(temp, "%lf", &Negative_reinforcement);
   else
      {
      printf(" Error(set_param): unknown param type: %s\n", name);
      return ERROR;
      }  /* else bad parameter name */

#ifdef DEBUG
   printf(" ---end set_param()---\n");
#endif
   return OK;
   }  /* set_param */

/********** read_default_opfiles **********/
/* parameters:  opfiles_file
   called by:   ga_init(), ga.c
                read_defaults, params.c
   actions:     Read from specified opfiles file, one line at a time.
		Set up the output files as specified in file.
		First number indicates if file is to be printed;
		second number indicates if header is to be printed.
		(1 = yes, 0 = no)  Second number is ignored if first is 0.

                Skip the comment lines which are denoted
                by a "#" or "%" xter in the first column.
		Each line contains the extension of an output file
		and a 1 if it is supposed to be printed during the
		run or 0 if it is not to be printed.
*/
int read_default_opfiles(char *opfiles_file)
   {
   char *aline;
   FILE *fp;
   int i;

#ifdef DEBUG
   printf(" ---in read_default_opfiles()--- %s\n", opfiles_file);
#endif

  /* open file */
   fp = fopen(opfiles_file, "r");
   if (fp == NULL)
      {
      printf(" Error(read_default_opfiles): cannot open file: %s\n",
		opfiles_file);
      return ERROR;
      }  /* if */
   printf(" Reading from file: %s\n", opfiles_file);

  /* allocate space for aline */
   aline = (char *)malloc(INPUT_LINE_LEN * sizeof(char));

  /* first line should give the maximum number of possible output files */
  /* allocate needed array space */
   if (get_next_line(fp, aline) != ENDOFFILE)
      {
      sscanf(aline, "%d", &Max_num_output_files);
      Output_file = (OUTPUT_FILE *)malloc(Max_num_output_files *
			sizeof(OUTPUT_FILE));
      }  /* if */

  /* now read rest of the non-comment lines up to above specified
     number of files -- any additional lines are ignored */
   i = 0;
   while (get_next_line(fp, aline) != ENDOFFILE && i < Max_num_output_files)
      {
      Output_file[i].extension = (char *)malloc(INPUT_LINE_LEN * sizeof(char));
      sscanf(aline, "%s %d", Output_file[i].extension, &Output_file[i].on);
      i++;
      }  /* while */

   free(aline);
   fclose(fp);

#ifdef DEBUG
   printf(" ---end read_default_opfiles()---\n");
#endif
   return OK;
   }  /* read_default_opfiles */

/********** read_opfiles **********/
/* parameters:  opfiles_file
   called by:   ga_init(), ga.c
                read_defaults, params.c
   actions:     Read from specified opfiles file, one line at
                a time.
                Skip the comment lines which are denoted
                by a "#" or "%" xter in the first column.
		Each line contains the extension of an output file
		and a 1 if it is supposed to be printed during the
		run or 0 if it is not to be printed.
*/
int read_opfiles(char *opfiles_file)
   {
   char *aline;
   FILE *fp;
   char *extension;
   int on;
   int i;

#ifdef DEBUG
   printf(" ---in read_opfiles()--- %s\n", opfiles_file);
#endif

  /* open file */
   fp = fopen(opfiles_file, "r");
   if (fp == NULL)
      {
      printf(" Error(read_default_opfiles): cannot open file: %s\n",
		opfiles_file);
      return ERROR;
      }  /* if */
   printf(" Reading from file: %s\n", opfiles_file);

  /* allocate space for aline */
   aline = (char *)malloc(INPUT_LINE_LEN * sizeof(char));
   extension = (char *)malloc(INPUT_LINE_LEN * sizeof(char));

   while (get_next_line(fp, aline) != ENDOFFILE)
      {
      sscanf(aline, "%s %d", extension, &on);
      i = get_file_pointer(extension);
      if (i == -1)
         {
         printf(" Error(read_opfiles): invalid extension: %s\n", extension);
         return ERROR;
         }  /* if */
      sprintf(Output_file[i].extension, "%s", extension);
      Output_file[i].on = on;
      }  /* while */

   free(aline);  
   free(extension);  
   fclose(fp);
#ifdef DEBUG
   printf(" ---end read_opfiles()---\n");
#endif
   return OK;
   }  /* read_opfiles */

/********** get_file_pointer **********/
/* parameters:	extension	of desired file
   called by:	read_opfiles(), params.c
   actions:	given an extension, goes thru Output_file and returns
		the array pointer to that file's array element.
		Returns -1 of not found.
*/
int get_file_pointer(char *extension)
   {
   int i;

   for (i=Max_num_output_files-1; i>=0; i--)
      {
      if (!strcmp(extension, Output_file[i].extension))  return i;
      }  /* for i */
   return -1;
   }  /* get_file_pointer */

/********** setup_output_files **********/
/* parameters:  aline           line of data on one file
                i               counter to Output_file
   called by:   ga_init(), ga.c
   actions:     Goes thru list of all possible output files
		(read from opfiles.default), and sets up Output_file[i].fp
		for those that are "on" for the current run.
		All Output_file[i].extension and .on entries should
		contain data, just need to decide which ones need .fp
		to be initialized.
*/
int setup_output_files()
   {
   int i;

#ifdef DEBUG
   printf(" ---in setup_output_files()---\n");
#endif

  /* i starts at 1 because array element 0 should always be for
     for the random file (so random should always be the first
     file extension specified in opfiles.default).  This is so
     that the random file can be decided on in get_random_seed()
     in init.c rather than here. */
   for (i=1; i<Max_num_output_files; i++)
      {
      /* if output file is on, set up .fp, otherwise do nothing */
      if (Output_file[i].on)
         {
         Output_file[i].filename = (char *)malloc(INPUT_LINE_LEN*sizeof(char));
         sprintf(Output_file[i].filename, "%s/run.%d/run.%d.%s",
		Output_path, Run_num, Run_num, Output_file[i].extension);
         Output_file[i].fp = fopen(Output_file[i].filename, "w");
         if (Output_file[i].fp == NULL)
            {
            printf(" Error(set_up_file): cannot open file: %s\n",
                           Output_file[i].filename);
            return ERROR;
            }  /* if */
         fclose(Output_file[i].fp);
         }  /* if */
      }  /* for i */

#ifdef DEBUG
   printf(" ---end setup_output_files()---\n");
#endif
   return OK;
   }  /* setup_output_files */

/********** file_on **********/
/* parameters:  extension       of desired file
   called by:  genops.c
   actions:     given an extension, goes thru Output_file and returns
		1 if that file is on (being printed to for this run)
		or 0 if that file is off (not to be printed to).
*/
int file_on(char *extension)
   {
   int i;
 
   for (i=Max_num_output_files-1; i>=0; i--)
      {
      if (!strcmp(extension, Output_file[i].extension))  
         {
         if (Output_file[i].on)
            {
            return 1;
            }
         else
            {
            return 0;
            }
         }
      }  /* for i */
   printf(" Error(file_on): unknown file extension: %s\n", extension);
   return 0;
   }  /* file_on */

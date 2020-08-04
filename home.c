/* Additional code-2
   Code for home page.*/

/* header file contains input/output related functions. */
#include <stdio.h>

/* header file contains system commands. */
#include <stdlib.h>

int main()
{   
    FILE *fp;
    fp=fopen("home.txt", "w");
    system("clear");
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n\t       \033[1;35m *****************************************************************************************************************************",fp);	    
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp); 
    fputs("\n\t       \033[1;35m * \033[1;36m       * * *     ***********                   *            * * * * *        *        *                                  \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m     *       *        *                        *            *                *        *                                  \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m    *                 *                  * * * * * * *      *                *  * * * * * * *                            \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m   *                  *                        *            *                *        *                                  \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m   *                  *     * *     *     *    *            *               **   *    *           * *      * *   * *     \033[1;35m *",fp);     
    fputs("\n\t       \033[1;35m * \033[1;36m   *        *****     *   *     *    *   *     *            * * * *       *  *        *         *     *   *  *  *    *   \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m   *                  *  *       *    * *      *            *           *    *   *    *        *       *     * *         \033[1;35m *",fp); 
    fputs("\n\t       \033[1;35m * \033[1;36m   *                  *  *  *  * *     *       *     *      *          *     *   *    *     *  *       *     *           \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m   *                  *  *            * *      *     *      *          *     *   *    *     *  *       *     *           \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m     *       *        *   *      *   *   *     *    *       *           *    *   *     *    *   *     *      *           \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m * \033[1;36m       * * *          *     * * *   *     *      * *        * * * * *     *  *   *      * *       * *        *           \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                          \033[1;33m Made with\033[1;31m \u2764 \033[1;33m by Sujay for Code Cops 2020.                                      \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m *                                                                                                                          \033[1;35m *",fp);
    fputs("\n\t       \033[1;35m ***************************************************************************************************************************** \033[0m", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fputs("\n", fp);
    fclose(fp);
    system("cat home.txt");
    // remove("home.txt");
}

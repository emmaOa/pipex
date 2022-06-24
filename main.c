#include "pipex.h"

int main()
{
    char *s = ft_url("/home/codespace/.rbenv/shims:/vscode/bin/linux-x64/4af164ea3a06f701fe3e89a2bcbb421d2026b68f/bin/remote-cli:/home/codespace/.nvm/current/bin:/home/codespace/.npm-global/bin:/home/codespace/.python/current/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/home/codespace/.dotnet:/home/codespace/.dotnet/tools:/usr/local/sdkman/bin:/usr/local/sdkman/candidates/gradle/current/bin:/usr/local/sdkman/candidates/java/current/bin:/opt/maven/lts:/usr/local/go/bin:/go/bin:/usr/local/py-utils/bin:/opt/conda/condabin:/home/codespace/.java/current/bin:/home/codespace/.nodejs/current/bin:/home/codespace/.php/current/bin:/home/codespace/.ruby/current/bin:/home/codespace/.maven/current/bin:/home/codespace/.hugo/current/bin:/home/codespace/.local/bin:/opt/oryx:/opt/nodejs/lts/bin:/opt/dotnet/lts:/opt/python/latest/bin:/opt/php/lts/bin:/opt/php-composer:/opt/yarn/stable/bin:/opt/hugo/lts::/opt/java/lts/bin:/opt/maven/lts/bin:/opt/ruby/lts/bin:/usr/local/rvm/bin", "cat");
    printf("'%s'\n", s);
    free(s);
}
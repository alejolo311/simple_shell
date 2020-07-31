FROM alejolo311/hsh-enviroment
WORKDIR /shell_v2
COPY . .
RUN make
CMD [ "/bin/sh" ]
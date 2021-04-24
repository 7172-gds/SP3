FROM debian
COPY sp3 .
RUN chmod ugo+x sp3
CMD ./sp3

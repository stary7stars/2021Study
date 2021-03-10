package hello.demo.sigleton;

public class SingletonService {

    private static final SingletonService instance = new SingletonService();

    public static SingletonService getInstance() {
        return instance;
    }

    // private 생성자로 만들어서 다른데서 new로 생성자 쓰려고 하면 막는다.
    private SingletonService() {
        System.out.println("싱글톤 객체 로직 호출");
    }
}

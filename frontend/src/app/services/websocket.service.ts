import {Injectable} from '@angular/core';
import {Observable, Observer, Subject} from 'rxjs';
import {AnonymousSubject} from "rxjs/internal/Subject";

@Injectable({
  providedIn: 'root'
})
export class WebsocketService {
  public subject!: Subject<string>;

  constructor() {
  }

  public connect(url: string): Subject<string> {
    if (!this.subject) {
      this.subject = this.create(url);
    }
    return this.subject;
  }

  private create(url: string): Subject<string> {
    const ws = new WebSocket(url);
    const observable = new Observable((obs: Observer<string>) => {
      ws.onmessage = event => {
        const data = event.data;
        obs.next(data);
      };
      ws.onerror = obs.error.bind(obs);
      ws.onclose = obs.complete.bind(obs);
      return ws.close.bind(ws);
    })
    const observer: Observer<string> = {
      next: (data: string) => {
        if (ws.readyState === WebSocket.OPEN) {
          console.log(`SENT DATA: ${data}`);
          ws.send(data);
        }
      },
      error: (err: string) => {
        console.log(err)
      },
      complete: () => {
      }
    }
    return new AnonymousSubject<string>(observer, observable);
  }
}
